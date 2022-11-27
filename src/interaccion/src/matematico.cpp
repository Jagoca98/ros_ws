#include <interaccion/matematico.h>

matematico::matematico(ros::NodeHandle nh, ros::Rate rate):nh_(nh), rate_(rate)
{
    sub_ = nh_.subscribe("/user_topic", 1000, &matematico::callback, this);
    multiply_ = nh_.serviceClient<interaccion::multiplicador>("multiplicar");
    update_ = false;
}

void matematico::multiply(void){
    try
    {
        multiply_.call(srv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void matematico::callback(const interaccion::usuario &msg){
    
    srv.request.entrada = msg.infPersonal.edad;
    
    ROS_DEBUG_STREAM("Lectura correcta");
    update_ = true;
}

void matematico::imprimir(void){
    std::cout << "Edad x2: "  << srv.response.resultado << std::endl;

}

void matematico::run(void){
    std::cout << ("\t\t\t\tMATEMATICO") << std::endl;
    while(ros::ok()){
        if(update_){
            multiply();
            imprimir();
            update_ = false;
        }    
        rate_.sleep();
        ros::spinOnce();
        ROS_DEBUG("Mensaje publicado");
    }
}