# gzb_reader 


**The gzb_plugin_ws uses the code from here:** 
https://sites.google.com/view/gazebo-plugin-tutorials/8-ros-gazebo-light-control-plugin

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



