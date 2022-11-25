#include <interaccion/emocion_usuario.h>

int main(int argc, char** argv){

    ros::init(argc, argv, "emocion_node");
    ros::NodeHandle nh;
    ros::Rate rate(1);
    emocion_usuario lista(nh, rate);

    lista.run();
    
    return 0;
}

