#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <ros/wall_timer.h>


class reloj
{
/**
 * @class Clock
 * @brief It display the UTC and Local format time at a rate of 3Hz.
 * Also it sends a msgs in /still_alive topic each minute.
 * 
 */
private:
    /* data */
    ros::NodeHandle nh_;
    ros::Publisher pub_;
    ros::Subscriber sub_reset_, sub_start_;
    ros::Rate rate_;
    ros::WallTime start_, end_;
    ros::Timer timer_;
    std_msgs::Bool firstMsg_, still_alive_;
    double execution_time_;
    boost::posix_time::ptime datetime_;

    /**
     * @brief Receives messages from /reset_topic and /start__topic
     * 
     * @param msg 
     */
    void callback(const std_msgs::String &msg);

    /**
     * @brief Publish in /still_alive each time the timer rings
     * 
     * @param event 
     */
    void timerCallback(const ros::TimerEvent &event);

    /**
     * @brief Prints the time in Local and UTC format
     * 
     */
    void imprimirHora(void);
    
public:
    reloj(ros::NodeHandle nh, ros::Rate rate);
    void run(void);
};