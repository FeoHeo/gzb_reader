#include <gazebo/gazebo.hh>
#include <gazebo/common/common.hh>
#include <gazebo/physics/physics.hh>
#include <ignition/math/Vector3.hh>
#include <ignition/math/Color.hh>

#include <ros/ros.h>
#include <std_msgs/String.h>

#include <functional>
#include <thread>
#include "ros/callback_queue.h"
#include "ros/subscribe_options.h"

namespace gazebo {

class LightController_ROS_Plugin : public ModelPlugin{};


}