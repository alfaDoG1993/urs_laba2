#include <ros/ros.h>
#include <kosenko_an_13345_2_2/ZodiacList.h>
#include "../include/zodiac_list.h"  // Словарь

bool get_days(kosenko_an_13345_2_2::ZodiacList::Request &req,
                      kosenko_an_13345_2_2::ZodiacList::Response &resp)
{
  bool flag = false;
  for (auto it = zodiac_list.begin(); it != zodiac_list.end(); ++it)
  {
    if (req.zodiac == it->first)
    {
      resp.days = it->second;
      ROS_INFO_STREAM(req.zodiac);
      ROS_INFO_STREAM(resp.days);
      flag = true;
      return true;
    }
  }
//  if (flag == false)
//  {
//      ROS_ERROR("Incorrect zodiac sign!");
//      return false;
//  }
//  else
//  {
//    flag = false;
//    return true;
//  }
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "get_zodiac_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("get_zodiac_days", get_days);
  ROS_INFO("...");
  ros::spin();

  return 0;
}
