#include <ros/ros.h>
#include <std_msgs/String.h>
#include <vector>
#include <interaccion/inf_personal_usuario.h>


class informacion_personal
{
/**
 * @class Personal information
 * @brief The personal information node will ask for the name,
 * age and possible languages spoken by an invented user. 
 * 
 */
private:
    /* data */
    ros::NodeHandle nh_;
    ros::Publisher pub_;
    ros::Rate rate_;
    interaccion::inf_personal_usuario persona_;
    pthread_t lectura;

    /**
     * @brief Asks for a new person
     * 
     * @return interaccion::inf_personal_usuario Returns an
     * inf_personal_usuario.msg
     */
    interaccion::inf_personal_usuario leer_persona(void);

    /**
     * @brief Return true if input is a number
     * 
     * @param s String to check
     * @return true If s is a number
     * @return false If s isn't a number 
     */
    bool isNumber(const std::string& s);
    

public:
    informacion_personal(ros::NodeHandle nh, ros::Rate rate);
    void run(void);
};