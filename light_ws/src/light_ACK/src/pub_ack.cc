#include "ros/ros.h"
#include "ros/common.h"

#include "std_msgs/Bool.h"
#include "std_msgs/String.h"

#include <iostream>

ros::Publisher pub;

void callBack(const std_msgs::Bool::ConstPtr &msg) {
    std_msgs::Bool pubMsg;
    pubMsg.data = true;

    std::cout << "Pub" << std::endl;

    pub.publish(pubMsg);
};

int main(int _argc , char** _argv) {

    ros::init(_argc , _argv , "ack_pub");
    ros::NodeHandle rosNode;

    std::cout << "Init done" << std::endl;

    pub = rosNode.advertise<std_msgs::Bool>("/server_bridge_msgs/cmd_ack" , 1);

    ros::Subscriber sub = rosNode.subscribe("/gzb_translator", 1 , &callBack);

    //const std_msgs::String::ConstPtr &ackReceived = ros::topic::waitForMessage<std_msgs::String>("/box_state");
    ros::spinOnce();
}

