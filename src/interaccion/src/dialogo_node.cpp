#include <interaccion/dialogo.h>

int main(int argc, char** argv){

    ros::init(argc, argv, "dialogo_node");
    ros::NodeHandle nh;
    ros::Rate rate(1);
    dialogo lista(nh, rate);

    lista.run();    
    return 0;
}

