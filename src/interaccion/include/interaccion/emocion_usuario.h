#include <ros/ros.h>
#include <std_msgs/String.h>
#include <vector>



class emocion_usuario
{
/**
 * @class User emotion
 * @brief The emotion node is in charge of asking users about
 * their feelings
 */
private:
    /* data */
    ros::NodeHandle nh_;
    ros::Publisher pub_;
    ros::Rate rate_;
    pthread_t lectura;
    std_msgs::String emocion_;

    /**
     * @brief Asks for an emotion input as a String
     * 
     * @return std::string Returns the emotion entered by the
     *  user
     */
    std::string leer_emocion(void);
    

public:
    emocion_usuario(ros::NodeHandle nh, ros::Rate rate);
    void run(void);
};