#include <ros/ros.h>
#include <sergeeva_aa_13345_2/NodService.h>
#include <stdlib.h>

bool get_nod(sergeeva_aa_13345_2::NodService::Request &req,
             sergeeva_aa_13345_2::NodService::Response &resp)
{
  int nod = int(std::min(std::min(req.a1, req.a2), req.a3));
  std::cout << nod;
  while (((int(req.a1) % nod) != 0 || \
         (int(req.a2) % nod)  != 0 || \
         (int(req.a3) % nod)) != 0 )
  {
    nod -= 1;
  }
  resp.nod = double(nod);
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
