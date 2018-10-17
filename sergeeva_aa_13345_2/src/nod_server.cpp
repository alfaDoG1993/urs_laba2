#include <ros/ros.h>
#include <sergeeva_aa_13345_2/NodService.h>

bool get_nod(sergeeva_aa_13345_2::NodService::Request &req,
             sergeeva_aa_13345_2::NodService::Response &resp)
{
// впиши сюда код: req - входящее  resp исходящее
	return 1;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "nod_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("get_nod", get_nod);

  ros::spin();

  return 0;
}
