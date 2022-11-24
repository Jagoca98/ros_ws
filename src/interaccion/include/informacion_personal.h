#include <ros/ros.h>
#include <pthread.h>
#include <std_msgs/String.h>
#include <vector>


class informacion_personal
{
private:
    /* data */
    ros::NodeHandle nh_;
    ros::Publisher pub_user_;
    ros::Rate rate_;
    std::vector<std_msgs::string> personas_;
    


public:
    informacion_personal(ros::NodeHandle nh, ros::Rate rate);
    ~informacion_personal(void);
    void run(void);
};