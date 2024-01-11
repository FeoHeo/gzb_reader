# gzb_reader 


**The plugin_ws uses the code from here(with some modification):** 
https://sites.google.com/view/gazebo-plugin-tutorials/8-ros-gazebo-light-control-plugin

Remember that I have modified the code to work on this specific project that I'm doing, you should learn the logic from the site but the only the code in this repo works

## **Getting Started**
First, create a folder for the workspace. Something like *my_ws* would do.

Then, run the following commands

    cd my_ws
    mkdir src
    cd src
    git clone https://github.com/FeoHeo/gzb_reader.git
    cd ..
    catkin_make
**NOTE**: If catkin_make does not work, delete folders /build and /devel in both folders /light_ws and /plugin_ws then try again


**This concludes getting started part, below are code functionality**



**Launch the world for light control**

    . go_to_gzb_plugin.sh
    roslaunch light_controller_ros lightcontroller.launch

**Run the light processes**

    . go_to_light_ack.sh
From here, you can run either ack for light or code reader for light

run light code reader

    rosrun reader light_core_reader


run light ack 

Extra configuration will be needed if you wanna run light ack. Aside from this code, you will need: mqtt_bridge and MqttX

Install and config MqttX: You can download it from Ubuntu Software store(recommended) 

Or download from here: https://mqttx.app/downloads

Now install mqtt_bridge from the github repo: https://github.com/groove-x/mqtt_bridge

Connect MqttX to mqtt_bridge. Go to /mqtt_bridge/config/demo_params.yaml

From .yaml file, change MqttX connection value(host and port) to the ones in the .yaml file

From here, add a subscription to the mqtt_bridge topic. If you look at any of the bridge under 'bridge:' in .yaml, you can see 'factory: mqtt_bridge.bridge:RosToMqttBridge' and under there 'topic_to: randomName', the 'randomName' will be the name of the mqtt_bridge topic => so you should connect MqttX subsrciption to that topic


Add the following code to your demo_params.yaml

    - factory: mqtt_bridge.bridge:RosToMqttBridge
    msg_type: std_msgs.msg:Bool
    topic_from: /server_bridge_msgs/cmd_ack
    topic_to: ~/echo

From here, connect MqttX to mqtt_bridge. And you can run light_ACK

    cd /light_ws
    source devel/setup.bash
    rosrun light_ACK ack_mqtt



