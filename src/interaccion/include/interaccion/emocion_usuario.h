#include <ros/ros.h>
#include <std_msgs/String.h>
#include <vector>



class emocion_usuario
{
private:
    /* data */
    ros::NodeHandle nh_;
    ros::Publisher pub_;
    ros::Rate rate_;
    pthread_t lectura;
    std_msgs::String emocion_;

    std::string leer_emocion(void);
    

public:
    emocion_usuario(ros::NodeHandle nh, ros::Rate rate);
    void run(void);
};