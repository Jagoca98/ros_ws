#include <interaccion/empaquetador.h>

empaquetador::empaquetador(ros::NodeHandle nh, ros::Rate rate):nh_(nh), rate_(rate)
{
    pub_ = nh_.advertise<interaccion::usuario>("user_topic",1000);
    sub_emocion_ = nh_.subscribe("/emocion_topic", 1000, &empaquetador::callback_emocion, this);
    sub_infPersonal_ = nh_.subscribe("/inf_pers_topic", 1000, &empaquetador::callback_infPersonal, this);
    sub_posicion_ = nh_.subscribe("/pos_usuario_topic", 1000, &empaquetador::callback_posUsuario, this);
    infPersonal_update = posicion_update = emocion_update = updatePub = false;
}

void empaquetador::callback_infPersonal(const interaccion::inf_personal_usuario &msg){
    infPersonal_.nombre = msg.nombre;
    infPersonal_.edad = msg.edad;
    infPersonal_.idiomas = msg.idiomas;
    ROS_DEBUG_STREAM("Lectura correcta de informacion personal");
    infPersonal_update = true;
}


void empaquetador::callback_posUsuario(const interaccion::pos_usuario &msg){
    posicion_.x = msg.x;
    posicion_.y = msg.y;
    posicion_.z = msg.z;
    ROS_DEBUG_STREAM("Lectura correcta de posicion");
    posicion_update = true;
}


void empaquetador::callback_emocion(const std_msgs::String &msg){
    emocion_.data = msg.data;
    ROS_DEBUG_STREAM("Lectura correcta de emocion");
    emocion_update = true;
}

interaccion::usuario empaquetador::crear_mensaje(void){
    interaccion::usuario usuario;

    if(infPersonal_update && posicion_update && emocion_update){
        usuario.infPersonal.nombre = infPersonal_.nombre;
        usuario.infPersonal.edad = infPersonal_.edad;
        usuario.infPersonal.idiomas = infPersonal_.idiomas;
        usuario.emocion = emocion_.data;
        usuario.posicion.x = posicion_.x;
        usuario.posicion.y = posicion_.y;
        usuario.posicion.z = posicion_.z;
        infPersonal_update = posicion_update = emocion_update = false;
        updatePub = true;
        ROS_DEBUG("Actualizamos!!");
    }
    return usuario;
}



void empaquetador::run(void){
    std::cout << ("\t\t\t\tEMPAQUETADOR") << std::endl;
    while(ros::ok()){
        usuario_ = crear_mensaje();
        if(updatePub){
            pub_.publish(usuario_);
        }
        updatePub=false;
        rate_.sleep();
        ros::spinOnce();
        ROS_DEBUG("Mensaje publicado");
    }
}