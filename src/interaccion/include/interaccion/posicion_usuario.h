#include <ros/ros.h>
#include <std_msgs/String.h>
#include <vector>
#include <interaccion/pos_usuario.h>


class posicion_usuario
{
private:
    /* data */
    ros::NodeHandle nh_;
    ros::Publisher pub_;
    ros::Rate rate_;
    interaccion::pos_usuario posicion_;

    interaccion::pos_usuario leer_posicion(void);
    bool isNumber(const std::string& s);    

public:
    posicion_usuario(ros::NodeHandle nh, ros::Rate rate);
    void run(void);
};