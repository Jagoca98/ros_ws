#include <interaccion/empaquetador.h>

int main(int argc, char** argv){

    ros::init(argc, argv, "empaquetador_node");
    ros::NodeHandle nh;
    ros::Rate rate(1);
    empaquetador lista(nh, rate);

    lista.run();    
    return 0;
}

