#include <ros/ros.h>
#include <std_msgs/String.h>
#include <vector>
#include <interaccion/usuario.h>
#include <interaccion/inf_personal_usuario.h>


class empaquetador
{
/**
 * @class Packer
 * @brief The packer node is responsible for assembling the information
 *  received by each of the three nodes into a single ros message to be
 *  sent to the dialogue_node.
 */
private:
    /* data */
    ros::NodeHandle nh_;
    ros::Publisher pub_;
    ros::Subscriber sub_emocion_;
    ros::Subscriber sub_infPersonal_;
    ros::Subscriber sub_posicion_;
    ros::Rate rate_;

    interaccion::inf_personal_usuario infPersonal_;
    interaccion::pos_usuario posicion_;
    std_msgs::String emocion_;
    interaccion::usuario usuario_;
    bool infPersonal_update, posicion_update, emocion_update, updatePub;

    /**
     * @brief Receives messages from /inf_pers_topic.
     * 
     * @param msg
     */
    void callback_infPersonal(const interaccion::inf_personal_usuario &msg);
    
    /**
     * @brief Receives messages from /pos_usuario_topic.
     * 
     * @param msg 
     */
    void callback_posUsuario(const interaccion::pos_usuario &msg);
    
    /**
     * @brief Receives messages from /emocion_topic.
     * 
     * @param msg 
     */
    void callback_emocion(const std_msgs::String &msg);

    /**
     * @brief Merges the information received by 
     * callbacks into a usuario.msg

     * @return interaccion::usuario
     */
    interaccion::usuario crear_mensaje(void);
    

public:
    empaquetador(ros::NodeHandle nh, ros::Rate rate);
    void run(void);
};