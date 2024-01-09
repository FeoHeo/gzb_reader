
#include "ros/ros.h"
#include "std_msgs/String.h"

#include <std_msgs/ColorRGBA.h>
#include <std_msgs/UInt8.h>
#include <functional>

ros::Publisher code_pub;


void colorCallBack(const std_msgs::ColorRGBA::ConstPtr& msg) {

std_msgs::UInt8 codeOutput;
    if( msg->r == 0 &&
        msg->g == 0 &&
        msg->b == 1) {
            codeOutput.data = 1;

    } else 
    if( msg->r == 0 &&
        msg->g == 1 &&
        msg->b == 0) {
            codeOutput.data = 2;

    } else
    if( msg->r == 1 &&
        msg->g == 1 &&
        msg->b == 1) {
            codeOutput.data = 3;

    } else
    if( msg->r == 1 &&
        msg->g == 1 &&
        msg->b == 0) {
            codeOutput.data = 4;
    };

    
    code_pub.publish(codeOutput);

    return;
}



int main(int argc, char **argv) {

    ros::init(argc, argv, "gzb_reader");
    ros::NodeHandle rosNode;

    code_pub = rosNode.advertise<std_msgs::UInt8>("/server_bridge_msgs/at_landing_box_in",1);

    ros::Subscriber color_sub = rosNode.subscribe("/light_rgb", 1, colorCallBack);

    ros::spin();

    return 0;
}