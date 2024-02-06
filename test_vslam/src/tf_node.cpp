#include "ros/ros.h"
#include <tf/transform_broadcaster.h>
#include "std_msgs/String.h"


#include <sstream>

int main(int argc, char **argv)
{

    ros::init(argc, argv, "tfpub");
  
   ros::NodeHandle n;
  int32_t publish_rate_ = 100;
    tf::TransformBroadcaster tf_br_;
    tf::StampedTransform tf_map_to_odom_;

    // set up parent and child frames
    tf_map_to_odom_.frame_id_ = std::string("odom");
    tf_map_to_odom_.child_frame_id_ = std::string("camera_link");

    // set up publish rate
    ros::Rate loop_rate(publish_rate_);

    // main loop
    while (ros::ok())
    {
    // time stamp
    tf_map_to_odom_.stamp_ = ros::Time::now();

    // specify actual transformation vectors from odometry
    // NOTE: zeros have to be substituted with actual variable data
    tf_map_to_odom_.setOrigin(tf::Vector3(0.0f, 0.0f, 0.0f));
    tf_map_to_odom_.setRotation(tf::Quaternion(0.0f, 0.0f, 0.0f));

    // broadcast transform
    tf_br_.sendTransform(tf_map_to_odom_);

    ros::spinOnce();
    loop_rate.sleep();
    }

  return 0;
}