#include <ros/ros.h>
#include <tuv_md_13345_2_2/GetSpeedModule.h>
#include <cstdlib>
#include <std_msgs/Float32.h>

int main( int argc, char **argv )
{
    ros::init( argc, argv, "get_speed_module_client" );
    ros::NodeHandle n;

    ros::ServiceClient client = n.serviceClient<tuv_md_13345_2_2::GetSpeedModule>( "get_speed_mod" );
    tuv_md_13345_2_2::GetSpeedModule srv;

    while ( ros::ok() )
    {
        float x = 0;
        float y = 0;
        float z = 0;

        ROS_INFO_STREAM( "Input x:" );
        std::cin >> x;
        ROS_INFO_STREAM( "Input y:" );
        std::cin >> y;
        ROS_INFO_STREAM( "Input z:" );
        std::cin >> z;

       srv.request.x = x;
       srv.request.y = y;
       srv.request.z = z;
       if ( client.call( srv ) )
       {
           ROS_INFO_STREAM( "Speed module:" << srv.response.module );
       }
       else
       {
           ROS_INFO_STREAM( "Failed to call service" );
       }
    }

    return 0;
}
