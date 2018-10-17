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
    ros::Rate loop_rate(1);

    while (ros::ok())
    {
      for (auto it = call_name_list.begin(); it != call_name_list.end(); it++)
      {
          for(auto jt = call_name_list.begin(); jt != call_name_list.end(); jt++)
          {
            srv.request.Name = it->first + " " +jt->second;

            ROS_INFO_STREAM("I wanna find :" << srv.request.Name);

            if (client.call(srv))
            {
              ROS_INFO_STREAM("Number: \n" << srv.response.Phone);
            }
            else
            {
              ROS_ERROR_STREAM("Failed Name. Please, chek Name...");
            }

            ros::spinOnce();
            loop_rate.sleep();
          }
      }
    }
}

