# FUN4_6503 
# Design a system for controlling a 3 DOF robotic arm.

# Part 0: Install and setup environment in your computer.
**Install ROS2 Humble**
[Install ROS 2 packages](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debs.html)
**Note:** in *Desktop Install* you must install follow me.
```
sudo apt install ros-humble-desktop-full
```
and onother part You can follow the link I provided.
**Install dependencies**
-   install numpy version 1.23.5 
    ```
    pip3 install numpy==1.23.5
    ```
-   install robotics toolbox for python
    ```
    pip3 install roboticstoolbox-python
    ```
    **Note:**  When i import roboticstoolbox in code i have a error 
    ```
    ImportError: cannot import name 'plotvol3' from 'spatialmath.base.graphics'
    ```
    If you have same ploblem as me. you can copy this command in terminal home directory. If not you can pass this section.
    ```
    sudo apt-get remove python3-matplotlib
    # later on if you need to apt install packages, you will likely get:
    # E: Unmet dependencies. Try 'apt --fix-broken install' with no packages (or specify a solution).
    # doing that will unfortunately bring back python3-matplotlib.
    # Again, this is very hacky.
    ```
    It should work.
-   install my project
    
