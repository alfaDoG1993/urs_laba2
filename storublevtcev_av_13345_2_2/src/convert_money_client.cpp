#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include "storublevtcev_av_13345_2_2/ConvertMoney.h"


int main(int argc, char **argv)
{
    ros::init(argc, argv, "convert_money_client");
    ros::NodeHandle nh;
     ros::ServiceClient client = nh.serviceClient<storublevtcev_av_13345_2_2::ConvertMoney>("convert_money");

    storublevtcev_av_13345_2_2::ConvertMoney srv;

    ROS_INFO("Convert money client begin");
    float rate=1;
    ros::Rate loop(rate);
    float money=00;
    while(ros::ok())
        {
            money+=1;
            if(money>10000) money=0.1;
            srv.request.rub=money;
            if(client.call(srv))
                {
                    ROS_INFO_STREAM("\n"<<money<<" RUB=\n"<<srv.response.usd<<" USD\n"<<srv.response.eur<<" EUR\n" <<srv.response.gbr<<" GBR\n"<<srv.response.ugx<<" UGX\n\n");
                }
            else
                {
                    ROS_INFO_STREAM("\nFAIL\n\n");
                }
            ros::spinOnce();
            loop.sleep();
        }


    return 0;

}
