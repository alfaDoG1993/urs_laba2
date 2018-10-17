#include "ros/ros.h"
#include "bagulina_ms_13345_2_2/GetDay.h"
#include <map>
#include <utility>
#include <string>


using namespace std;
map <int,int> Calendar;
map <int,string> DayNames {{0,"Sunday"}, {1,"Monday"}, {2,"Tuesday"}, {3,"Wednesday"}, {4,"Thursday"},
                           {5,"Friday"}, {6,"Saturday"}};

void calInit ()
{
    Calendar.insert(pair<int,int>(1,31));
    Calendar.insert(pair<int,int>(2,28));
    Calendar.insert(pair<int,int>(3,31));
    Calendar.insert(pair<int,int>(4,30));
    Calendar.insert(pair<int,int>(5,31));
    Calendar.insert(pair<int,int>(6,30));
    Calendar.insert(pair<int,int>(7,31));
    Calendar.insert(pair<int,int>(8,31));
    Calendar.insert(pair<int,int>(9,30));
    Calendar.insert(pair<int,int>(10,31));
    Calendar.insert(pair<int,int>(11,30));
    Calendar.insert(pair<int,int>(12,31));
}

string getDayOfWeek(int a, int b)
{
    int offset = 0;
    int numOfDays = 0;
    for (auto i = Calendar.begin(); i->first < b; i++)
    {
        numOfDays += i->second;
    }
    numOfDays += a;
    ROS_INFO("Days in year pasts %d ", numOfDays);
    return DayNames[numOfDays%7+offset];
}


bool trueDate(int a, int b)
{
    if (Calendar.empty())
        calInit();
    auto month = Calendar.find(b);
    if (month == Calendar.end())
    {
        ROS_INFO("Month %d doesn't exist!", b);
        return false;
    }
    if (a > (month->second))
    {
         ROS_INFO("Day %d doesn't exist!", a);
         return false;
    }
    else
        return true;
}


bool getDay(bagulina_ms_13345_2_2::GetDay::Request  &req,
         bagulina_ms_13345_2_2::GetDay::Response &res)
{
  if (!trueDate(req.a, req.b))
  {
      ROS_ERROR("Incorrect data!");
      return false;
  }

  res.day = getDayOfWeek(req.a, req.b);
  ROS_INFO("request: day=%d, month=%d", (int)req.a, (int)req.b);
  ROS_INFO_STREAM("sending back response: " << res.day);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "get_week_day_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("get_week_day", getDay);
  ROS_INFO("Ready to get the day of the week");
  ros::spin();

  return 0;
}
