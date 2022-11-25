#include <ros/ros.h>
#include <std_msgs/String.h>
#include <vector>
#include <interaccion/usuario.h>
#include <interaccion/emocion_usuario.h>
#include <interaccion/informacion_personal.h>


class empaquetador
{
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


    void callback_infPersonal(const interaccion::inf_personal_usuario &msg);
    void callback_posUsuario(const interaccion::pos_usuario &msg);
    void callback_emocion(const std_msgs::String &msg);


    interaccion::usuario crear_mensaje(void);
    

public:
    empaquetador(ros::NodeHandle nh, ros::Rate rate);
    void run(void);
};