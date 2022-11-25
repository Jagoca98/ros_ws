#include <interaccion/posicion_usuario.h>

int main(int argc, char** argv){

    ros::init(argc, argv, "cpp_sub");
    ros::NodeHandle nh;
    ros::Rate rate(1);
    posicion_usuario lista(nh, rate);

    lista.run();
    
    return 0;
}

