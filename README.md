# gzb_reader 


**The gzb_plugin_ws uses the code from here:** 
https://sites.google.com/view/gazebo-plugin-tutorials/8-ros-gazebo-light-control-plugin

## **Getting Started**
First, create a folder for the workspace. Something like *my_ws* would do.

Then, run the following commands

    cd my_ws
    mkdir src
    cd src
    git clone https://github.com/FeoHeo/gzb_reader.git
    cd ..
    catkin_make

**This concludes getting started part, below are code functionality**



**Launch the world for light control**

    . go_to_gzb_plugin.sh
    roslaunch light_controller_ros lightcontroller.launch

**Run the light processes**

    . go_to_light_ack.sh
From here, you can run either ack for light or code reader for light

run light ack 

    rosrun light_ACK ack_mqtt to run ack for light
run light code reader

    rosrun reader light_core_reader



