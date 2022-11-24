#include <informacion_personal.h>


informacion_personal::informacion_personal(ros::NodeHandle nh, ros::Rate rate):nh_(nh), rate_(rate)
{
    pub_user_ = nh_.advertise<std_msgs::string>("informacion_personal",1000);
}

informacion_personal::~informacion_personal()
{
}

void informacion_personal::avanza(void){
    vel.linear.x = 0.5;
    vel.angular.z = 0;  
    pub_vel_.publish(vel);  
}

void informacion_personal::run(void){
    ROS_INFO("Hola");
    rate_.sleep();
    while(ros::ok()){
        ros::spinOnce();
    }
}