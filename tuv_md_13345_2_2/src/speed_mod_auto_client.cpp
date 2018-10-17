#include <ros/ros.h>
#include <tuv_md_13345_2_2/GetSpeedModule.h>
#include <cstdlib>
#include <std_msgs/Float32.h>
#include <ctime>

int main( int argc, char **argv )
{
    ros::init( argc, argv, "get_speed_module_auto_client" );
    ros::NodeHandle n;

    ros::ServiceClient client = n.serviceClient<tuv_md_13345_2_2::GetSpeedModule>( "get_speed_mod" );
    tuv_md_13345_2_2::GetSpeedModule srv;

    float rate = 1;
    n.param<float>( "speed_publisher_rate", rate, 1 );
    ros::Rate loop(rate);

    while ( ros::ok() )
    {
        srv.request.x = (float)rand()/RAND_MAX;
        srv.request.y = (float)rand()/RAND_MAX;
        srv.request.z = (float)rand()/RAND_MAX;

        ROS_INFO_STREAM( "Speed: " << srv.request.x << " " << srv.request.y << " " << srv.request.z );

        if ( client.call( srv ) )
        {
            //ROS_INFO_STREAM( "Speed: " << srv.request.x << " " << srv.request.y << " " << srv.request.z );
            ROS_INFO_STREAM( "Speed module:" << srv.response.module );
        }
        else
        {
            ROS_INFO_STREAM( "Failed to call service" );
        }

        ros::spinOnce();
        loop.sleep(); 
    }

    return 0;
}
