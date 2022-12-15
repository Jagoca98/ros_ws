#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include <vector>
#include <interaccion/usuario.h>
#include <interaccion/multiplicador.h>


class dialogo
{
/**
 * @class Dialogue
 * @brief The dialogue node is responsible for the terminal display
 *  of each message it receives from the packer node.
 */

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
    
    /**
     * @brief Multiply age by 2
     * 
     */
    void multiply(void);

    /**
     * @brief Callback of /user_topic. Receives messages of 
     * users and call the multiplier service
     * @param msg 
     */
    void callback(const interaccion::usuario &msg);
    /**
     * @brief Callback of /still_alive. Receives messages
     * from the clock_node
     * @param msg 
     */
    void callback_alive(const std_msgs::Bool &msg);
    /**
     * @brief Prints usurario's information
     * 
     * @param usuario is an usuario.msg
     */
    void imprimir(const interaccion::usuario &usuario);
    
public:
    dialogo(ros::NodeHandle nh, ros::Rate rate);
    void run(void);
};