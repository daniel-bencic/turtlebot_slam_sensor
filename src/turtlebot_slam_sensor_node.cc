#include <ros/ros.h>

#include "../include/turtlebot_slam_sensor/turtlebot_slam_sensor.h"

int main(int argc, char *argv[])
{
        ros::init(argc, argv, "turtlebot_slam_sensor");

        ros::NodeHandle nh{ "~" };
        turtlebot_slam_sensor::TurtlebotSLAMSensor sensor{ nh };

        ros::Rate r(10);
        while (ros::ok()) {
                ros::spinOnce();
                sensor.PublishPillarPosition();
                r.sleep();
        }

        return 0;
}
