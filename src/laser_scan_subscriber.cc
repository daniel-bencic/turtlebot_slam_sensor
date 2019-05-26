#include "../include/turtlebot_slam_sensor/laser_scan_subscriber.h"

namespace turtlebot_slam_sensor {
        sensor_msgs::LaserScan kLatestLaserScan{ };

        LaserScanSubscriber::~LaserScanSubscriber() { }
        
        void LaserScanSubscriber::Callback(const sensor_msgs::LaserScan& scan) const
        {
                kLatestLaserScan = scan;
        }
}
