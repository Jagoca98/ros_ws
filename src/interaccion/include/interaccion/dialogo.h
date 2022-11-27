#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include <vector>
#include <interaccion/usuario.h>
#include <interaccion/multiplicador.h>


class dialogo
{
private:
    /* data */
    ros::NodeHandle nh_;
    ros::Subscriber sub_, sub_alive_;
    ros::Publisher pubStart_;
    ros::Publisher pubReset_;
    ros::Rate rate_;
    ros::ServiceClient multiply_;
    interaccion::multiplicador srv;
    interaccion::usuario usuario_;
    std_msgs::String msg_;
    bool update_, firstTime_;
    std::string text_, command_;

    void multiply(void);
    void callback(const interaccion::usuario &msg); 
    void callback_alive(const std_msgs::Bool &msg);
    void imprimir(const interaccion::usuario &usuario);
    
public:
    dialogo(ros::NodeHandle nh, ros::Rate rate);
    void run(void);
};