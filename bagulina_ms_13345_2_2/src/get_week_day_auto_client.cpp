#include "ros/ros.h"
#include "bagulina_ms_13345_2_2/GetDay.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "get_week_day_client");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<bagulina_ms_13345_2_2::GetDay>("get_week_day");
  bagulina_ms_13345_2_2::GetDay srv;

  float rate = 1;
  n.param<float>("day_publisher_rate",rate,1);
  ros::Rate loop(rate);
  while (ros::ok())
  {
    int day;
    int month;

    day = rand()%32;
    month = rand()%13;

    srv.request.a = day;
    srv.request.b = month;

    if (client.call(srv))
      ROS_INFO_STREAM("The day is: " << srv.response.day);
    else
      ROS_ERROR_STREAM("Failed to call service get_week_day or wrong data input");
    ros::spinOnce();
    loop.sleep();
  }
  return 0;
}
