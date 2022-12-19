#include <interaccion/dialogo.h>

dialogo::dialogo(ros::NodeHandle nh, ros::Rate rate):nh_(nh), rate_(rate)
{
    sub_ = nh_.subscribe("/user_topic", 1000, &dialogo::callback, this);
    sub_alive_ = nh_.subscribe("still_alive", 1000, &dialogo::callback_alive, this);
    pubStart_ = nh_.advertise<std_msgs::String>("start_topic", 1000);
    pubReset_ = nh_.advertise<std_msgs::String>("reset_topic", 1000);
    multiply_ = nh_.serviceClient<interaccion::multiplicador>("multiplicar");
    update_ = false;
    firstTime_ = true;
    msg_.data = "GoodMorning ut";
}

void dialogo::callback(const interaccion::usuario &msg){
    usuario_.infPersonal.nombre = msg.infPersonal.nombre;
    srv.request.entrada = usuario_.infPersonal.edad = msg.infPersonal.edad;
    usuario_.infPersonal.idiomas = msg.infPersonal.idiomas;
    usuario_.emocion = msg.emocion;
    usuario_.posicion.x = msg.posicion.x;
    usuario_.posicion.y = msg.posicion.y;
    usuario_.posicion.z = msg.posicion.z;
    ROS_DEBUG_STREAM("Lectura correcta");
    update_ = true;
    if(firstTime_){
        firstTime_ = false;
        pubStart_.publish(msg_);
        msg_.data = "GoodMorning x6";
    }else{
        pubReset_.publish(msg_);
    }
}

void dialogo::callback_alive(const std_msgs::Bool &msg){
    if(msg.data){
        std::cout << "El reloj sigue vivo" << std::endl;
        text_ = "El reloj sigue vivo";
        command_ = "espeak -v es \"" + text_ +"\"";
        system(command_.c_str());
    }
}

void dialogo::multiply(void){
    try
    {
        multiply_.call(srv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void dialogo::imprimir(const interaccion::usuario &usuario){
    // ROS_INFO_STREAM(usuario);
    std::cout << usuario;
    text_ = "Nombre: \"" + usuario.infPersonal.nombre + "\"";
    command_ = "espeak -v es -p 99\"" + text_ +"\"";
    system(command_.c_str());
    text_ = "Edad: \"" + std::to_string(usuario.infPersonal.edad) + "\"";
    command_ = "espeak -v es p 0\"" + text_ +"\"";
    system(command_.c_str());

    for(int i=0; i<usuario.infPersonal.idiomas.size(); i++){
        text_ = "Idioma \"" + std::to_string(i) + usuario.infPersonal.idiomas[i] + "\"";
        command_ = "espeak -v es p 99\"" + text_ +"\"";
        system(command_.c_str());
    }
    text_ = "Emocion: \"" + usuario.emocion + "\"";
    command_ = "espeak -v es p 0\"" + text_ +"\"";
    system(command_.c_str());
    text_ = "Poscion: \"" + std::to_string(usuario.posicion.x) + "\"," + std::to_string(usuario.posicion.y) + "\"," + std::to_string(usuario.posicion.z) + "\"";
    command_ = "espeak -v es p 99\"" + text_ +"\"";
    system(command_.c_str());

    std::cout << "Edad x2: " << srv.response.resultado << std::endl;
    text_ = "Edad por 2: \"" + std::to_string(srv.response.resultado) + "\"";
    command_ = "espeak -v es p 0\"" + text_ +"\"";
    system(command_.c_str());
}

void dialogo::run(void){
    std::cout << ("\t\t\t\tDIALOGO") << std::endl;
    while(ros::ok()){
        if(update_){
            multiply();
            imprimir(usuario_);
            update_ = false;
        }    
        rate_.sleep();
        ros::spinOnce();
        ROS_DEBUG("Mensaje publicado");
    }
}