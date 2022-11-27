#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <ros/wall_timer.h>


class reloj
{
private:
    /* data */
    ros::NodeHandle nh_;
    ros::Publisher pub_;
    ros::Subscriber sub_reset_, sub_start_;
    ros::Rate rate_;
    ros::WallTime start_, end_;
    std_msgs::Bool firstMsg_;
    double execution_time_;
    boost::posix_time::ptime datetime_;


    void callback(const std_msgs::String &msg);
    void imprimirHora(void);
    
public:
    reloj(ros::NodeHandle nh, ros::Rate rate);
    void run(void);
};