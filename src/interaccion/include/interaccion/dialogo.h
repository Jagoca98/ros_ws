#include <ros/ros.h>
#include <std_msgs/String.h>
#include <vector>
#include <interaccion/usuario.h>
#include <interaccion/multiplicador.h>


class dialogo
{
private:
    /* data */
    ros::NodeHandle nh_;
    ros::Subscriber sub_;
    ros::Rate rate_;
    ros::ServiceClient multiply_;
    interaccion::multiplicador srv;
    interaccion::usuario usuario_;
    bool update_;

    void multiply(void);
    void callback(const interaccion::usuario &msg); 
    void imprimir(const interaccion::usuario &usuario);
    
public:
    dialogo(ros::NodeHandle nh, ros::Rate rate);
    void run(void);
};