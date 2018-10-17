#include <ros/ros.h>
#include <skorokhod_oi_13345_2_2/triangle_info.h>
#include "string.h"
#include "iostream"
#define PI 3.14159
bool get_answer(skorokhod_oi_13345_2_2::triangle_info::Request &req,
                      skorokhod_oi_13345_2_2::triangle_info::Response &resp)
{
  float a = req.first;
  float b = req.second;
  float c = req.third;
  float square,perimeter,height_a,height_b,height_c,angle_ab,angle_ac,angle_bc;
  perimeter = a + b + c;
  float half_perimeter = perimeter/2.0;
  square = sqrt(half_perimeter * (half_perimeter - a)*
                (half_perimeter - b) * (half_perimeter - c));
  height_a = 2 * square / a;
  height_b = 2 * square / b;
  height_c = 2 * square / c;
  if(a>=b && a>=c)
  {
    angle_bc = (acos(height_a/b) + acos(height_a/c))*180/PI;
    angle_ac = (PI/2 - acos(height_a/c))*180/PI;
    angle_ab = (PI/2 - acos(height_a/b))*180/PI;
  }
  if(b>=a && b>=c)
  {
    angle_ac = (acos(height_b/c) + acos(height_b/a))*180/PI;
    angle_ab = (PI/2 - acos(height_b/a))*180/PI;
    angle_bc = (PI/2 - acos(height_b/c))*180/PI;
  }
  if(c>=a && c>=b)
  {
    angle_ab = (acos(height_c/a)+acos(height_c/b))*180/PI;
    angle_ac = (PI/2 - acos(height_c/a))*180/PI;
    angle_bc = (PI/2 - acos(height_c/b))*180/PI;
  }

  std::string answer = "S = ";
  answer.append(std::to_string(square));
  answer.append(", P = ");
  answer.append(std::to_string(perimeter));
  answer.append(", angle AB = ");
  answer.append(std::to_string(angle_ab));
  answer.append(", angle BC = ");
  answer.append(std::to_string(angle_bc));
  answer.append(", angle AC = ");
  answer.append(std::to_string(angle_ac));
  answer.append(", hA = ");
  answer.append(std::to_string(height_a));
  answer.append(", hB = ");
  answer.append(std::to_string(height_b));
  answer.append(", hC = ");
  answer.append(std::to_string(height_c));
  resp.answer = answer;

  ROS_INFO_STREAM("answer is: "<<resp.answer);
  return true;

}
int main(int argc, char *argv[])
{
  ros::init(argc, argv, "get_triangle_info_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("get_triangle_info", get_answer);
  ROS_INFO("Ready to calculate smth");
  ros::spin();

  return 0;
}
