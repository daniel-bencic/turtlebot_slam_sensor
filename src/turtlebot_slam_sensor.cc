#include <std_msgs/Header.h>
#include <turtlebot_common/parameter_accessor.h>
#include <turtlebot_common/laser_scan.h>
#include "../include/turtlebot_slam_sensor/turtlebot_slam_sensor.h"
#include "../include/turtlebot_slam_sensor/algorithm/laser_scan_utility.h"

namespace turtlebot_slam_sensor {
        TurtlebotSLAMSensor::TurtlebotSLAMSensor(ros::NodeHandle& nh) : nh_{ nh }
        {
                turtlebot_common::ParameterAccessor param{ nh };
                std::string topic_sub = param.GetParameter<std::string>(
                                                "topic_sub");
                std::string topic_pub = param.GetParameter<std::string>(
                                                "topic_pub");
                uint32_t qs = static_cast<uint32_t>(
                                param.GetParameter<int>(
                                        "queue_size"));
                pub_ = turtlebot_common::Publisher<turtlebot_slam_sensor::pillar_pos>{ nh, topic_pub, qs };
                sub_ = LaserScanSubscriber{ nh, topic_sub, qs };
                sub_.Subscribe();
        }

        void TurtlebotSLAMSensor::PublishPillarPosition()
        {
                turtlebot_slam_sensor::pillar_pos pos{ };
                pos.header = kLatestLaserScan.header;

                if (kLatestLaserScan.ranges.empty() || !IsHit(kLatestLaserScan.intensities)) {
                        pos.dist = -1;
                        pos.angle = -1;
                } else {
                        turtlebot_common::LaserScan s{ kLatestLaserScan.ranges,
                                                        kLatestLaserScan.intensities, 
                                                        kLatestLaserScan.angle_min,
                                                        kLatestLaserScan.angle_increment };
                        turtlebot_common::PolarPoint p = ExtractClosestPoint(s);
                        pos.dist = p.dist;
                        pos.angle = p.angle;
                }

                pub_.Publish(pos);
        }
}


