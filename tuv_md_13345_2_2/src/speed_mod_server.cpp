#include <ros/ros.h>
#include <tuv_md_13345_2_2/GetSpeedModule.h>
#include <cmath>
#include <std_msgs/Float64.h>


bool get_speed_mod( tuv_md_13345_2_2::GetSpeedModule::Request & req,
                   tuv_md_13345_2_2::GetSpeedModule::Response & resp )
{
    resp.module = pow( req.x, 2 ) + pow( req.y, 2 ) + pow( req.z, 2 );
    resp.module = sqrt( resp.module );

    ROS_INFO( "Speed vector:[ %f, %f, %f ] ", req.x, req.y, req.z );
    ROS_INFO_STREAM( "Module:" << resp.module );

    return true;
}

int main( int argc, char **argv )
{
    ros::init( argc, argv, "get_speed_module_server" );
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService( "get_speed_mod", get_speed_mod );
    ROS_INFO( "Ready to get vector modules..." );
    ros::spin();

    return 0;
}
