#include <interaccion/posicion_usuario.h>


bool posicion_usuario::isNumber(const std::string& s){
    for(char const &ch : s){
        if(std::isdigit(ch) == 0)
            return false;
    }
    return true;
}

posicion_usuario::posicion_usuario(ros::NodeHandle nh, ros::Rate rate):nh_(nh), rate_(rate)
{
    pub_ = nh_.advertise<interaccion::pos_usuario>("pos_usuario_topic",1000);
}

interaccion::pos_usuario posicion_usuario::leer_posicion(void){

    std::string x, y, z;
    interaccion::pos_usuario posicion;

    do{
        std::cout << "Posicion x: ";
        std::cin >> x;
    }while(!posicion_usuario::isNumber(x));
    posicion.x = std::stoi(x);

    do{
        std::cout << "Posicion y: ";
        std::cin >> y;
    }while(!posicion_usuario::isNumber(y));
    posicion.y = std::stoi(y);

    do{
        std::cout << "Posicion z: ";
        std::cin >> z;
    }while(!posicion_usuario::isNumber(z));
    posicion.z = std::stoi(z);
    
    return posicion;
}


void posicion_usuario::run(void){
    ROS_INFO("Hola");
    while(ros::ok()){
        posicion_ = leer_posicion();
        pub_.publish(posicion_);
        rate_.sleep();
        ROS_DEBUG("Posicion leida");
    }
}