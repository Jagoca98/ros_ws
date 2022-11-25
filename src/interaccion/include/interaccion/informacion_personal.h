#include <ros/ros.h>
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
    interaccion::inf_personal_usuario persona_;
    pthread_t lectura;

    interaccion::inf_personal_usuario leer_persona(void);
    bool isNumber(const std::string& s);
    

public:
    informacion_personal(ros::NodeHandle nh, ros::Rate rate);
    void run(void);
};