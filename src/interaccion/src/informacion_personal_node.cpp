#include <interaccion/informacion_personal.h>

int main(int argc, char** argv){

    ros::init(argc, argv, "cpp_sub");
    ros::NodeHandle nh;
    ros::Rate rate(0.1);
    informacion_personal lista(nh, rate);

    lista.run();
    
    return 0;
}

