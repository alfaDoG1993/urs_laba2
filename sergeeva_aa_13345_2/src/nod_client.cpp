#include "ros/ros.h"
#include <sergeeva_aa_13345_2/NodService.h>
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "nod_client");
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<sergeeva_aa_13345_2::NodService>("get_nod");
  sergeeva_aa_13345_2::NodService srv;

  while (ros::ok()){
    double a1;
    double a2;
    double a3;
    ROS_INFO_STREAM("Input 3 values ");
    std::cin >> a1;
    std::cin >> a2;
    std::cin >> a3;
    srv.request.a1 = a1;
    srv.request.a2 = a2;
    srv.request.a3 = a3;
    if (client.call(srv))
      ROS_INFO_STREAM("nod: " << srv.response.nod);
    else
    {
      ROS_ERROR_STREAM("Failed to get nod...");
    }
  }
}
