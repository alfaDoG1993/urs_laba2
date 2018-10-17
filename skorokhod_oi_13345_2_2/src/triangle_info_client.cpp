#include <ros/ros.h>
#include <skorokhod_oi_13345_2_2/triangle_info.h>
#include <ctime>

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "auto_triangle_info_client");
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<skorokhod_oi_13345_2_2::triangle_info>("get_triangle_info");
  skorokhod_oi_13345_2_2::triangle_info srv;

  float rate = 1;
  n.param<float>("triangle_parameter_publisher_rate",rate,1);
  ros::Rate loop(rate);
  while (ros::ok()){
    float a,b,c;
    a = rand();
    a /= RAND_MAX;
    b = rand();
    b /= RAND_MAX;
    c = rand();
    c /= RAND_MAX;
    srv.request.first = a;
    srv.request.second = b;
    srv.request.third = c;
    if (client.call(srv))
      ROS_INFO_STREAM("answer to " << a<<" "<< b <<" " << c <<" : " << srv.response.answer);
    else
    {
      ROS_ERROR_STREAM("Failed to get citations. Please? chek citations number...");
    }
    ros::spinOnce();
    loop.sleep();
  }
  return 0;
}
