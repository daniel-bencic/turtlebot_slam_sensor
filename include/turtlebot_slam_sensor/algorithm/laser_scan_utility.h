#include <vector>

#include <turtlebot_common/polar_point.h>
#include <turtlebot_common/laser_scan.h>

namespace turtlebot_slam_sensor {
        bool IsHit(std::vector<float> intensities);
        turtlebot_common::PolarPoint ExtractClosestPoint(turtlebot_common::LaserScan);
}
