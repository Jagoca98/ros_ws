#include <interaccion/reloj.h>

int main(int argc, char** argv){

    ros::init(argc, argv, "reloj_node");
    ros::NodeHandle nh;
    ros::Rate rate(3);
    reloj lista(nh, rate);

    lista.run();    
    return 0;
}

