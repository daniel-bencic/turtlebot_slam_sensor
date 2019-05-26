#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <turtlebot_common/subscriber.h>
#include <turtlebot_common/publisher.h>
#include <turtlebot_slam_sensor/pillar_pos.h>
#include "laser_scan_subscriber.h"

namespace turtlebot_slam_sensor {
        class TurtlebotSLAMSensor {
                public:
                        TurtlebotSLAMSensor(ros::NodeHandle& nh);
                        void PublishPillarPosition();

                private:
                        ros::NodeHandle& nh_;
                        LaserScanSubscriber sub_;
                        turtlebot_common::Publisher<turtlebot_slam_sensor::pillar_pos> pub_;
        };
}
