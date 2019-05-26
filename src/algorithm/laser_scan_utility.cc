#include <algorithm>

#include "../../include/turtlebot_slam_sensor/algorithm/laser_scan_utility.h"

namespace turtlebot_slam_sensor {
        bool IsHit(std::vector<float> intensities)
        {
                std::vector<float>::iterator it = std::max_element(std::begin(intensities), std::end(intensities));
                return *it > 0 ? true : false;
        }
        
        turtlebot_common::PolarPoint ExtractClosestPoint(turtlebot_common::LaserScan scan)
        {
                std::vector<float>::iterator it = std::min_element(std::begin(scan.ranges), std::end(scan.ranges));
                return turtlebot_common::PolarPoint{ *it, scan.angle_min + (it - std::begin(scan.ranges)) * scan.angle_inc };
        }
}
