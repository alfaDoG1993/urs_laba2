#include "ros/ros.h"
#include "bagulina_ms_13345_2_2/GetDay.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "get_week_day_client");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<bagulina_ms_13345_2_2::GetDay>("get_week_day");
  bagulina_ms_13345_2_2::GetDay srv;

  while (ros::ok())
  {
      int day;
      int month;
      ROS_INFO_STREAM("Input the number of the day and month: ");

      std::cin >> day;
      std::cin >> month;

      srv.request.a = day;
      srv.request.b = month;

      if (client.call(srv))
      {
        ROS_INFO_STREAM("The day is: " << srv.response.day);
      }
      else
      {
        ROS_ERROR_STREAM("Failed to call service get_week_day or wrong data input");
      }
  }

  return 0;
}
