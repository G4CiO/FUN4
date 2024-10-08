#!/usr/bin/env python3

"""
This program is free software: you can redistribute it and/or modify it 
under the terms of the GNU General Public License as published by the Free Software Foundation, 
either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. 
If not, see <https://www.gnu.org/licenses/>.

created by Thanacha Choopojcharoen at CoXsys Robotics (2022)
"""

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import os
import xacro    
    
def generate_launch_description():
    


    pkg = get_package_share_directory('fun4_description')
    rviz_path = os.path.join(pkg,'config','display.rviz')
    rviz = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz',
        arguments=['-d', rviz_path],
        output='screen')
    
    path_description = os.path.join(pkg,'robot','visual','my-robot.xacro')
    robot_desc_xml = xacro.process_file(path_description).toxml()
    #robot_desc_xml = xacro.process_file(path_description,mappings={'robot_name': namespace}).toxml()
    
    parameters = [{'robot_description':robot_desc_xml}]
    #parameters.append({'frame_prefix':namespace+'/'})

    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=parameters
    )

    joint_state_publisher_gui = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui'
    )


    random_node = Node(
        package='fun4_description',
        executable='random_target.py'
    )

    joint_state_publisher = Node(
        package='fun4_description',
        executable='joint_state_publisher.py',
        output='screen'
    )

    end_effector_pose = Node(
        package='fun4_description',
        executable='end_effector_pose.py',
        output='screen'
    )

    inverse_pose_kinematics = Node(
        package='fun4_description',
        executable='inverse_pose_kinematics.py',
        output='screen'
    )

    teleoperation = Node(
        package='fun4_description',
        executable='teleoperation.py',
        output='screen'
    )

    auto = Node(
        package='fun4_description',
        executable='auto.py',
        output='screen'
    )

    launch_description = LaunchDescription()    
    launch_description.add_action(rviz)
    launch_description.add_action(robot_state_publisher)
    launch_description.add_action(random_node)
    launch_description.add_action(end_effector_pose)
    # launch_description.add_action(joint_state_publisher)
    # launch_description.add_action(joint_state_publisher_gui)
    launch_description.add_action(inverse_pose_kinematics)
    launch_description.add_action(teleoperation)
    launch_description.add_action(auto)
    
    return launch_description