#include <interaccion/informacion_personal.h>


informacion_personal::informacion_personal(ros::NodeHandle nh, ros::Rate rate):nh_(nh), rate_(rate)
{
    pub_ = nh_.advertise<interaccion::inf_personal_usuario>("inf_pers_topic",1000);
}

interaccion::inf_personal_usuario informacion_personal::leer_persona(void){

    std::vector<std::string> idiomas;
    std::string idioma;
    interaccion::inf_personal_usuario persona;
    persona.idiomas.clear();

    std::cout << "Nombre: ";
    std::cin.ignore();
    std::getline(std::cin, persona.nombre,'\n');
    std::cout << "Edad: ";
    std::cin >> persona.edad;
    std::cout << "Idiomas [0 para terminar]: ";
    do{
        std::cin >> idioma;
        idiomas.push_back(idioma);
    }while(idiomas.back()!="0");
    persona.idiomas.resize(idiomas.size()-1);

    for(int i=0; i<idiomas.size(); i++){
        idiomas.pop_back();
        persona.idiomas[i] = idiomas.back();
    }
    return persona;
}

void informacion_personal::run(void){
    ROS_INFO("Hola");
    while(ros::ok()){
        persona_ = leer_persona();
        pub_.publish(persona_);
        rate_.sleep();
        ROS_DEBUG("Persona leida");
    }
}