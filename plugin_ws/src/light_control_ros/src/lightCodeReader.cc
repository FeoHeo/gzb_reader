#include <gazebo/gazebo.hh>
#include <gazebo/common/common.hh>
#include <gazebo/physics/physics.hh>
#include <ignition/math/Color.hh>
#include <ignition/math/Vector3.hh>

#include <ros/ros.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/String.h>

#include <functional>


namespace gazebo {

    class LightNameReader_ROS_Plugin : public ModelPlugin {
    public:
        void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
        {

            if (!ros::isInitialized()) // check if ros is initialized or not
            {
                ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized");
                return;
            }

            ROS_INFO("Light reader loaded");

            this->sub_light = ros_node.subscribe("/box_state", 1, &LightNameReader_ROS_Plugin::nameCallBack, this);
            //                                    topic name , queue size, callback, this pointer(to access class member fn)
            // store model pointer 
            this->model = _model;

            // initlize tranport node
            transport::NodePtr node(new transport::Node());
            node->Init();

            this->pub_code = ros_node.advertise<std_msgs::UInt8>("/server_bridge_msgs/at_landing_box_info", 10);

        }

    public:

        //ros callback function
        void nameCallBack(const std_msgs::String::ConstPtr &msg)
        {
            std_msgs::UInt8 returnCode;
            returnCode.data = codeFind(msg->data.c_str());

            ROS_INFO("Published: %d", returnCode);
            pub_code.publish(returnCode);
        }

        int codeFind(std::string strInput) {
            if(strInput == "error") {
                return 0;

            } else if(strInput == "closed") {
                return 1;

            } else if(strInput == "opened") {
                return 2;

            } else if(strInput == "partly_closed") {
                return 3;

            } else if(strInput == "partly_opened") {
                return 4;

            }
        }

    private:
        physics::ModelPtr model; // Pointer to the model

    private:
        ros::NodeHandle ros_node;      // ros node handler
        ros::Subscriber sub_light;     // ros sub

        ros::Publisher pub_code;
    };
    // Register this plugin with the simulator

    GZ_REGISTER_MODEL_PLUGIN(LightNameReader_ROS_Plugin);
};
