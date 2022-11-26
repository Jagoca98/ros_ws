#include <interaccion/emocion_usuario.h>

emocion_usuario::emocion_usuario(ros::NodeHandle nh, ros::Rate rate):nh_(nh), rate_(rate)
{
    pub_ = nh_.advertise<std_msgs::String>("emocion_topic",1000);
}

std::string emocion_usuario::leer_emocion(void){

    std::string emocion;

    std::cout << "Emocion: ";
    // std::cin.ignore();
    std::getline(std::cin, emocion,'\n');
    
    return emocion;
}



void emocion_usuario::run(void){
    std::cout << ("\t\t\t\tEMOCION DEL USUARIO") << std::endl;
    while(ros::ok()){
        emocion_.data = leer_emocion();
        pub_.publish(emocion_);
        rate_.sleep();
        ROS_DEBUG("Emocion leida");
    }
}