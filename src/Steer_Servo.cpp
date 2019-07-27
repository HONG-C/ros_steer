#include "ros/ros.h"         // ROS Default Header File
#include "std_msgs/UInt16.h" // MsgTutorial Message File Header. The header file is automatically created when building the package.

int main(int argc, char **argv) // Node Main Function
{
    ros::init(argc, argv, "Steer_Servo"); // Initializes Node Name
    ros::NodeHandle nh;                   // Node handle declaration for communication with ROS system

    // Declare publisher, create publisher 'ros_pub' using the 'MsgTutorial'
    // message file from the 'ros_tutorials_topic' package. The topic name is
    // 'ros_tutorial_msg' and the size of the publisher queue is set to 100.
    ros::Publisher ros_pub = nh.advertise<std_msgs::UInt16>("servo", 100);

    // Set the loop period. '10' refers to 10 Hz and the main loop repeats at 0.1 second intervals
    ros::Rate loop_rate(1);

    std_msgs::UInt16 msg; // Declares message 'msg' in 'MsgTutorial' message file format
    int count = 0;        // Variable to be used in message

    while (ros::ok())
    {
        for (int i = 0; i <= 4; ++i)
        {
            //msg.stamp = ros::Time::now(); // Save current time in the stamp of 'msg'
            msg.data = count; // Save the the 'count' value in the data of 'msg'

            ROS_INFO("hello!"); // Prints the 'stamp.sec' message

            ROS_INFO("Your servo motor's angle is %d degree.", count); // Prints the 'data' message

            ros_pub.publish(msg); // Publishes 'msg' message

            loop_rate.sleep(); // Goes to sleep according to the loop rate defined above.

            count = count + 30; // Increase count variable by one
        }
        for (int i = 0; i <= 4; ++i)
        {
            msg.data = count; // Save the the 'count' value in the data of 'msg'

            ROS_INFO("hello!"); // Prints the 'stamp.sec' message

            ROS_INFO("Your servo motor's angle is %d degree.", count); // Prints the 'data' message

            ros_pub.publish(msg); // Publishes 'msg' message

            loop_rate.sleep(); // Goes to sleep according to the loop rate defined above.

            count = count - 30; // Increase count variable by one
        }
    }

    return 0;
}