#include <interaccion/reloj.h>

reloj::reloj(ros::NodeHandle nh, ros::Rate rate):nh_(nh), rate_(rate)
{
    pub_ = nh_.advertise<std_msgs::Bool>("still_alive", 1000);
    sub_reset_ = nh_.subscribe("/reset_topic", 1000, &reloj::callback, this);
    sub_start_ = nh_.subscribe("/start_topic", 1000, &reloj::callback, this);
    firstMsg_.data = true;
}

void reloj::callback(const std_msgs::String &msg){
    if(firstMsg_.data){
        firstMsg_.data = false;
    }
    start_ = ros::WallTime::now();
    ROS_DEBUG_STREAM("Lectura correcta");
}

void reloj::imprimirHora(void){
    datetime_ = boost::posix_time::microsec_clock::universal_time();
    std::cout << "Current Time and Date: " << datetime_ << std::endl;
    std::cout << "Elapsed Time: " << execution_time_ << std::endl;
}

void reloj::run(void){
    std::cout << ("\t\t\t\tRELOJ") << std::endl;
    ros::spinOnce();
    while(ros::ok()){ 
        rate_.sleep();
        if(!firstMsg_.data){
            end_ = ros::WallTime::now();
            execution_time_ = (end_ - start_).toSec();
            imprimirHora();
        }
        ros::spinOnce();
        ROS_DEBUG("Mensaje publicado");
    }
}