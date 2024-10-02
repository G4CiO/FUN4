#!/usr/bin/python3
import roboticstoolbox as rtb
import numpy as np


from sensor_msgs.msg import JointState
from spatialmath import SE3
from math import pi
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, Twist
from fun4_interfaces.srv import ChangeMode
from scipy.spatial.transform import Rotation as R

class Teleoperation(Node):

    def __init__(self):
        super().__init__('teleoperation')
        self.get_logger().info('teleoperation node has start')
        # timer pub
        self.dt = 0.01
        # Pub
        self.joint_state_pub = self.create_publisher(JointState, '/joint_states', 10)
        # Sub 
        self.cmd_vel_sub = self.create_subscription(Twist, '/cmd_vel', self.callback_cmd_vel, 10)
        self.end_pose_sub = self.create_subscription(PoseStamped, '/end_effector', self.callback_end_pose, 10)
        self.joint_state_sub = self.create_subscription(JointState, '/joint_states', self.joint_state_callback, 10)
        # Service Server (รับ mode เข้ามา)
        self.take_mode = self.create_service(ChangeMode, '/mode_pose', self.callback_user)

        self.q = np.array([0.0, 0.0, 0.0])
        self.linear_vel = np.array([0.0, 0.0, 0.0])
        self.mode = 0
        self.teleop_mode = 1
        self.temp = None
        self.q_sol = []

    def joint_state_callback(self, msg: JointState):
        if len(msg.position) >= 3:
            self.q = np.array(msg.position[:3])  # Update the current joint positions with the feedback

    def pub_joint_states(self, q):
        joint_msg = JointState()
        joint_msg.name = ['joint_1', 'joint_2', 'joint_3']
        joint_msg.header.stamp = self.get_clock().now().to_msg()

        # Ensure q contains valid float values
        if np.all(np.isfinite(q)) and np.all(np.abs(q) < 1e6):  # Adding a reasonable range check
            joint_msg.position = q.tolist()  # Convert NumPy array to list of floats
            self.joint_state_pub.publish(joint_msg)
        else:
            self.get_logger().error(f"Invalid joint positions: {q}")

    def callback_cmd_vel(self, msg:Twist):
        linear_vel_x = msg.linear.x
        linear_vel_y = msg.linear.y
        linear_vel_z = msg.linear.z
        self.linear_vel = [linear_vel_x,linear_vel_y,linear_vel_z]
        self.control()

    def callback_end_pose(self, msg:PoseStamped):
        qx = msg.pose.orientation.x
        qy = msg.pose.orientation.y
        qz = msg.pose.orientation.z
        qw = msg.pose.orientation.w
        rotation = R.from_quat([qx, qy, qz, qw])
        self.rotation_matrix = rotation.as_matrix()

    def control(self):
        if self.mode == 2:
            robot = rtb.DHRobot(
                [
                    rtb.RevoluteMDH(alpha = 0.0,a = 0.0,d = 0.2,offset = 0.0),
                    rtb.RevoluteMDH(alpha = pi/2,a = 0.0,d = 0.12,offset = pi/2),
                    rtb.RevoluteMDH(alpha = 0,a = 0.25,d = -0.1,offset = pi/2),

                ],tool = SE3.Tx(0.28),
                name = "RRR_Robot"
            )

            # Compute Jacobian
            J = robot.jacob0(self.q)
            self.J_pos = J[0:3, :]  # Position part of the Jacobian

            # Singularity checking by determinant
            self.det_J = np.linalg.det(self.J_pos)
            # det_threshold = 1e-3
            self.det_threshold = 1e-2

            self.caljacob()

    def caljacob(self):
        if abs(self.det_J) < self.det_threshold:
            self.get_logger().warning("Singularity detected. Stopping movement. Please change to Mode 1 or 3 to change manipurator to another pose.")
            return 
        
        if self.teleop_mode == 1:
            # Compute joint velocities (q_dot)
            q_dot = np.linalg.pinv(self.J_pos) @ self.linear_vel
        elif self.teleop_mode == 2:
            # Use the rotation matrix to modify the linear velocity
            q_dot = np.linalg.pinv(self.J_pos) @ (self.rotation_matrix @ self.linear_vel)
        else:
            self.get_logger().warn(f'No Teleop mode {self.teleop_mode}. Please change only Teleop mode "1" or "2" ')
            return


        # Update joint angles
        self.q = self.q + q_dot * self.dt

        # Publish joint states
        self.pub_joint_states(self.q)


    def callback_user(self,request:ChangeMode.Request, response:ChangeMode.Response):
        self.mode = request.mode    
        self.teleop_mode = request.teleop_mode    

        x = request.pose.x
        y = request.pose.y
        z = request.pose.z
    
        if self.mode == 1:
            r_min = 0.03
            r_max = 0.535
            distance_squared = x**2 + y**2 + (z-0.2)**2
            if r_min**2 <= distance_squared <= r_max**2:
                response.config_check_mode1 = True

            robot = rtb.DHRobot(
                [
                    rtb.RevoluteMDH(alpha = 0.0,a = 0.0,d = 0.2,offset = 0.0),
                    rtb.RevoluteMDH(alpha = pi/2,a = 0.0,d = 0.12,offset = pi/2),
                    rtb.RevoluteMDH(alpha = 0,a = 0.25,d = -0.1,offset = pi/2),

                ],tool = SE3.Tx(0.28),
                name = "RRR_Robot"
            )

            # Desired end effector pose
            T_Position = SE3(x, y, z)
            q_sol_ik_LM, *_ = robot.ikine_LM(T_Position,mask=[1,1,1,0,0,0],q0=[0,0,0])
            response.config_mode1 = [q_sol_ik_LM[0], q_sol_ik_LM[1], q_sol_ik_LM[2]]

            response.change_mode_success = True
        if self.mode == 2:
            if self.teleop_mode  == 1 or self.teleop_mode == 2:
                response.change_teleop_mode_success = True
            self.get_logger().info(f'Change to mode {self.mode} Teleoperation ')
            response.change_mode_success = True
            response.config_mode1 = []
        if self.mode == 3:
            response.change_mode_success = True
            response.config_mode1 = []
        return response

def main(args=None):
    rclpy.init(args=args)
    node = Teleoperation()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()