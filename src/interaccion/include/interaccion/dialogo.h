#include <ros/ros.h>
#include <std_msgs/String.h>
#include <vector>
#include <interaccion/usuario.h>


class dialogo
{
private:
    /* data */
    ros::NodeHandle nh_;
    ros::Subscriber sub_;
    ros::Rate rate_;
    interaccion::usuario usuario_;
    bool update_;

    void callback(const interaccion::usuario &msg); 
    void imprimir(const interaccion::usuario &usuario);
    
public:
    dialogo(ros::NodeHandle nh, ros::Rate rate);
    void run(void);
};