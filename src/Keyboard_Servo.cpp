#include "ros/ros.h"         // ROS Default Header File
#include "std_msgs/String.h" // MsgTutorial Message File Header. The header file is automatically created when building the package.
#include <geometry_msgs/Twist.h>
#include "std_msgs/UInt16.h"

ros::Publisher ros_pub;
std_msgs::UInt16 angle;

void msgCallback(const geometry_msgs::Twist::ConstPtr &msg)
{
    ros::Rate loop_rate(1);
    ROS_INFO("recieve msg = %f", msg->angular.z); // Prints the 'stamp.sec' message
    float count = msg->angular.z;                 // Prints the 'stamp.nsec' message
    count = count + 2;                            // Prints the 'data' message
    char steer;

    switch (int(count))
    {
    case 1:
    {
        angle.data = 0;
        steer = 'R';
        break;
    }
    case 2:
    {
        angle.data = 60;
        steer = 'F';
        break;
    }
    case 3:
    {
        angle.data = 120;
        steer = 'L';
        break;
    }
    default:
    {
        break;
    }
    }
    ROS_INFO("YOUR CAR GOES %c.", steer);
    ros_pub.publish(angle);
    loop_rate.sleep();
}

int main(int argc, char **argv) // Node Main Function
{
    ros::init(argc, argv, "Keyboard_Servo"); // Initializes Node Name
    ros::NodeHandle nh;                      // Node handle declaration for communication with ROS system

    // Message callback function. This is a function is called when a topic
    // message named 'ros_tutorial_msg' is received. As an input message,
    // the 'MsgTutorial' message of the 'ros_tutorials_topic' package is received.

    ros_pub = nh.advertise<std_msgs::UInt16>("servo", 100);
    // Declares subscriber. Create subscriber 'ros_tutorial_sub' using the 'MsgTutorial'
    // message file from the 'ros_tutorials_topic' package. The topic name is
    // 'ros_tutorial_msg' and the size of the publisher queue is set to 100.

    ros::Subscriber ros_sub = nh.subscribe("cmd_vel", 100, msgCallback);

    // A function for calling a callback function, waiting for a message to be
    // received, and executing a callback function when it is received.
    ros::spin();
    return 0;
}