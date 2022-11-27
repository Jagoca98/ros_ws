#include <interaccion/matematico.h>

int main(int argc, char** argv){

    ros::init(argc, argv, "matematico_node");
    ros::NodeHandle nh;
    ros::Rate rate(1);
    matematico lista(nh, rate);

    lista.run();    
    return 0;
}

