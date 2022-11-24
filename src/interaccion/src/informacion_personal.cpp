#include <interaccion/informacion_personal.h>


informacion_personal::informacion_personal(ros::NodeHandle nh, ros::Rate rate):nh_(nh), rate_(rate)
{
    pub_ = nh_.advertise<interaccion::inf_personal_usuario>("inf_pers_topic",1000);
    interaccion::inf_personal_usuario persona;
}

void informacion_personal::leer_persona(interaccion::inf_personal_usuario &persona){
    std::vector<std::string> idiomas;
    std::string idioma;
    std::cout << "Nombre: ";
    std::cin >> persona.nombre;
    std::cout << "Edad: ";
    std::cin >> persona.edad;
    std::cout << "Idiomas: ";
    do{
        std::cin >> idioma;
        idiomas.push_back(idioma);
    }while(idiomas.back()!="0");
    idiomas.pop_back();

    for(std::string i : idiomas){
        persona.idiomas[i] = idiomas.back();
        idiomas.pop_back();
    }
}

void informacion_personal::run(void){
    ROS_INFO("Hola");
    while(ros::ok()){
        leer_persona(persona_);
        pub_.publish(persona_);
        rate_.sleep();
    }
}