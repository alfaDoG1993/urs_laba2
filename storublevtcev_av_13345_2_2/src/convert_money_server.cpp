#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include "storublevtcev_av_13345_2_2/ConvertMoney.h"


float usd_convert=0;
float eur_convert=0;
float gbr_convert=0;
float ugx_convert=0;

bool convert_money(storublevtcev_av_13345_2_2::ConvertMoney::Request &reg, storublevtcev_av_13345_2_2::ConvertMoney::Response &resp)
{
    if(ros::param::get("usd_convert",usd_convert))
        {
            resp.usd=reg.rub*usd_convert;
        }
    else
        {
            resp.usd=0;
        }

    if(ros::param::get("eur_convert",eur_convert))
        {
            resp.eur=reg.rub*eur_convert;
        }
    else
        {
            resp.eur=0;
        }

    if(ros::param::get("gbr_convert",gbr_convert))
        {
            resp.gbr=reg.rub*gbr_convert;
        }
    else
        {
            resp.gbr=0;
        }

    if(ros::param::get("ugx_convert",ugx_convert))
        {
            resp.ugx=reg.rub*ugx_convert;
        }
    else
        {
            resp.ugx=0;
        }
    return true;
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "convert_money_server");
    ros::NodeHandle nh;
    ros::ServiceServer service = nh.advertiseService("convert_money",convert_money);
    ROS_INFO("Convert money server ready...");
    ros::spin();

    return 0;

}
