#include "../include/Name.h"
#include <ros/ros.h>
#include <begin_srv/AddTwoInts.h>
#include "std_msgs/Bool.h"
#include <sstream>
#include <iostream>


bool get_name (begin_srv::AddTwoInts::Request &req,
               begin_srv::AddTwoInts::Response &resp)
{
  bool isNameFound = false;

  for (auto it = name_list.begin(); it != name_list.end(); it++)
  {
    if (req.Name == it->second)
    {
      resp.Phone += it->first + "\n";
      ROS_INFO_STREAM("Number: " << resp.Phone);
      isNameFound = true;
    }
    else
    { ; }
  }

  if(isNameFound != true)
  {
      ROS_ERROR("Incorrect Name!");
  }

  return isNameFound;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "get_citations_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("get_name", get_name);
  ROS_INFO("Ready to convey Name.");
  ros::spin();

  return 0;
}


