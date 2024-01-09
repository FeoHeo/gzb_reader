#include "gazebo/gazebo.hh"
#include "boost/shared_ptr.hpp"
#include "gazebo/common/common.hh"
#include "gazebo/transport/transport.hh"
#include "gazebo/gazebo_client.hh"
#include "ros/ros.h"

#include <iostream>
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"

typedef const boost::shared_ptr<const gazebo::msgs::Light> lightPtr;

ros::Publisher rosPub;
ros::Publisher rosTruePub;
std_msgs::Bool ackRespond;


void ackCb(const lightPtr &msg) {
    ackRespond.data = false;

    std::cout << "Called" << std::endl;

    //Listen to the /box_state
    rosPub.publish(ackRespond);
}

// void ackTrueCb(const std_msgs::Bool &msg) {
//     ackRespond.data = true;
//     rosTruePub.publish(ackRespond);
// }


int main(int _argc , char **_argv) {

    //Load gazebo
    gazebo::client::setup(_argc,_argv);

    //Create node for commute
    gazebo::transport::NodePtr node_gzb(new gazebo::transport::Node());
    node_gzb->Init();
    ros::init(_argc , _argv , "light_ACK");
    ros::NodeHandle rosNode;

    const std_msgs::String::ConstPtr &boxReceived = ros::topic::waitForMessage<std_msgs::String>("/box_state");


    //Advertise the Publisher
    rosPub = rosNode.advertise<std_msgs::Bool>("/gzb_translator" , 10);


    //Listen to /light/modify topic
    gazebo::transport::SubscriberPtr sub; 
    sub = node_gzb->Subscribe("/gazebo/default/light/modify" , &ackCb);


    gazebo::common::Time::MSleep(5000);

    gazebo::shutdown();
}

