#include "ros/ros.h"
#include "std_msgs/Bool.h"
#include "std_msgs/String.h"

#include <iostream>

ros::Publisher pub;

void ack_Cb(const std_msgs::String::ConstPtr &msg);

int main(int argc , char** argv) {

    ros::init(argc , argv , "mqtt_ack");
    ros::NodeHandle rosNode;

    ros::Subscriber sub;
    sub = rosNode.subscribe("/box_state" , 10 , &ack_Cb);

    //const std_msgs::String::ConstPtr &boxReceived = ros::topic::waitForMessage<std_msgs::String>("/box_state");

    pub = rosNode.advertise<std_msgs::Bool>("/server_bridge_msgs/cmd_ack",1);
    
    ros::spin();
    
    // if(sub.getNumPublishers() == 1) {
    //     ros::shutdown();
    // }

}

void ack_Cb(const std_msgs::String::ConstPtr &msg) {
    std_msgs::Bool pubAck;
    pubAck.data = true;


    pub.publish(pubAck);
    std::cout << "Called" << std::endl;
}