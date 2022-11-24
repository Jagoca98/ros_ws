#include <interaccion/informacion_personal.h>


informacion_personal::informacion_personal(ros::NodeHandle nh, ros::Rate rate):nh_(nh), rate_(rate)
{
    pub_ = nh_.advertise<interaccion::inf_personal_usuario>("inf_pers_topic",1000);
    interaccion::inf_personal_usuario persona;
    persona.nombre = "Jaime";
    persona.edad = 24;
    persona.idiomas[0] = "Espanol";
}

void informacion_personal::run(void){
    ROS_INFO("Hola");
    while(ros::ok()){
        pub_.publish(persona);
        ros::spinOnce();
    }
}