#include <ros/ros.h>
#include <std_msgs/String.h>
#include <vector>
#include <interaccion/pos_usuario.h>


class posicion_usuario
{
/**
 * @class User position
 * @brief The position node will ask for the user's coordinates
 * in space. They can be entered as many times as desired.
 * 
 */
private:
    /* data */
    ros::NodeHandle nh_;
    ros::Publisher pub_;
    ros::Rate rate_;
    interaccion::pos_usuario posicion_;

    /**
     * @brief Asks for a new position
     * 
     * @return interaccion::pos_usuario Returns an
     * pos_usuario.msg
     */
    interaccion::pos_usuario leer_posicion(void);

    /**
     * @brief Return true if input is a number
     * 
     * @param s String to check
     * @return true If s is a number
     * @return false If s isn't a number 
     */
    bool isNumber(const std::string& s);    

public:
    posicion_usuario(ros::NodeHandle nh, ros::Rate rate);
    void run(void);
};