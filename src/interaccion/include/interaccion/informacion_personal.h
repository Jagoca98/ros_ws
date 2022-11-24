#include <ros/ros.h>
#include <pthread.h>
#include <std_msgs/String.h>
#include <vector>
#include <interaccion/inf_personal_usuario.h>


class informacion_personal
{
private:
    /* data */
    ros::NodeHandle nh_;
    ros::Publisher pub_;
    ros::Rate rate_;
    interaccion::inf_personal_usuario persona;
    

public:
    informacion_personal(ros::NodeHandle nh, ros::Rate rate);
    void run(void);
};