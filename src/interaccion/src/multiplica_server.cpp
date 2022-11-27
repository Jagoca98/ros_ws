#include "ros/ros.h"
#include "interaccion/multiplicador.h"
#include <interaccion/usuario.h>
#include <cstdlib>

bool multiplicar(interaccion::multiplicador::Request  &req,
         interaccion::multiplicador::Response &res){
  res.resultado = req.entrada * 2;
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "multiplica_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("multiplicar", multiplicar);

  ros::spin();

  return 0;
}