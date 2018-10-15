#include "ros/ros.h"
#include <kosenko_an_13345_2_2/ZodiacList.h>
#include <cstdlib>
#include <iostream>
#include <ctime>


int main(int argc, char **argv)
{
  ros::init(argc, argv, "zodiac_sign_client");
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<kosenko_an_13345_2_2::ZodiacList>("get_zodiac_days");
  kosenko_an_13345_2_2::ZodiacList srv;

  std::string zodiac_signs[12] = {"Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn", "Aquarius", "Pisces"};

  float rate = 1.0;
  ros::Rate loop(rate);

  while (ros::ok()){
    int zodiac;
    ROS_INFO_STREAM("Input zodiac sign: ");
   // std::cin >> zodiac;

    int a,b;
    a = rand();
    b = a%12;


    srv.request.zodiac = zodiac_signs[b];
    ROS_INFO_STREAM(srv.request.zodiac);

    if (client.call(srv))
      ROS_INFO_STREAM(srv.response.days);
    else
    {
      ROS_ERROR_STREAM("Failed to get days. Enter another zodiac sign");
    }

    ros::spinOnce();
    loop.sleep();
  }
}
