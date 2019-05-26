#include <sensor_msgs/LaserScan.h>
#include <turtlebot_common/subscriber.h>

namespace turtlebot_slam_sensor {
        extern sensor_msgs::LaserScan kLatestLaserScan;

        class LaserScanSubscriber : public turtlebot_common::Subscriber<sensor_msgs::LaserScan> {
                public:
                        using turtlebot_common::Subscriber<sensor_msgs::LaserScan>::Subscriber;
                        ~LaserScanSubscriber();

                private:
                        void Callback(const sensor_msgs::LaserScan& scan) const;
        };
}
