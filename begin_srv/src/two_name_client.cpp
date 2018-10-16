#include "ros/ros.h"
#include "../include/Name.h"
#include "begin_srv/AddTwoInts.h"
#include <cstdlib>


int main(int argc, char **argv)
{
  ros::init(argc, argv, "name_number_client");
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<begin_srv::AddTwoInts>("get_name");
  begin_srv::AddTwoInts srv;

  int number;
  ROS_INFO_STREAM("Input Name: ");
  std::cin >> number;

  srv.request.Name = number;
  if (client.call(srv))
    ROS_INFO_STREAM("Number: " << srv.response.Phone);
  else
  {
    ROS_ERROR_STREAM("Failed Name. Please, chek Name...");
  }
}

