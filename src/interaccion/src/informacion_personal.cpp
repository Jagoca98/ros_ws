#include <interaccion/informacion_personal.h>


bool informacion_personal::isNumber(const std::string& s){
    for(char const &ch : s){
        if(std::isdigit(ch) == 0)
            return false;
    }
    return true;
}

informacion_personal::informacion_personal(ros::NodeHandle nh, ros::Rate rate):nh_(nh), rate_(rate)
{
    pub_ = nh_.advertise<interaccion::inf_personal_usuario>("inf_pers_topic",1000);
}

interaccion::inf_personal_usuario informacion_personal::leer_persona(void){

    std::vector<std::string> idiomas;
    std::string idioma, edad;
    interaccion::inf_personal_usuario persona;
    persona.idiomas.clear();

    std::cout << "Nombre: ";
    std::cin.ignore();
    std::getline(std::cin, persona.nombre,'\n');
    do{
        std::cout << "Edad: ";
        std::cin >> edad;
    }while(!informacion_personal::isNumber(edad));
    persona.edad = std::stoi(edad);

    std::cout << "Idiomas [0 para terminar]: ";
    do{
        std::cin >> idioma;
        idiomas.push_back(idioma);
    }while(idiomas.back()!="0");
    persona.idiomas.resize(idiomas.size()-1);

    if(idiomas.size()){
        for(int i=0; i<persona.idiomas.size(); i++){
            idiomas.pop_back();
            persona.idiomas[i] = idiomas.back();
        }
    }
    return persona;
}



void informacion_personal::run(void){
    std::cout << ("\t\t\t\tINFORMACION PERSONAL") << std::endl;
    while(ros::ok()){
        persona_ = leer_persona();
        pub_.publish(persona_);
        rate_.sleep();
        ROS_DEBUG("Persona leida");
    }
}