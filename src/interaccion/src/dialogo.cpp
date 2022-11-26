#include <interaccion/dialogo.h>

dialogo::dialogo(ros::NodeHandle nh, ros::Rate rate):nh_(nh), rate_(rate)
{
    sub_ = nh_.subscribe("/user_topic", 1000, &dialogo::callback, this);
    update_ = false;
}

void dialogo::callback(const interaccion::usuario &msg){
    usuario_.infPersonal.nombre = msg.infPersonal.nombre;
    usuario_.infPersonal.edad = msg.infPersonal.edad;
    usuario_.infPersonal.idiomas = msg.infPersonal.idiomas;
    usuario_.emocion = msg.emocion;
    usuario_.posicion.x = msg.posicion.x;
    usuario_.posicion.y = msg.posicion.y;
    usuario_.posicion.z = msg.posicion.z;
    ROS_DEBUG_STREAM("Lectura correcta");
    update_ = true;
}

void dialogo::imprimir(const interaccion::usuario &usuario){
    // ROS_INFO_STREAM(usuario);
    std::cout << usuario;

}

void dialogo::run(void){
    std::cout << ("\t\t\t\tDIALOGO") << std::endl;
    while(ros::ok()){
        if(update_){
            imprimir(usuario_);
            update_ = false;
        }    
        rate_.sleep();
        ros::spinOnce();
        ROS_DEBUG("Mensaje publicado");
    }
}