#include <interaccion/emocion_usuario.h>

int main(int argc, char** argv){

    ros::init(argc, argv, "cpp_sub");
    ros::NodeHandle nh;
    ros::Rate rate(1);
    emocion_usuario lista(nh, rate);

    lista.run();
    
    return 0;
}

