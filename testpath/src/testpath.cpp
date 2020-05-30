#include <ros/ros.h> 
#include <ros/console.h> 
#include <nav_msgs/Path.h> 
#include <std_msgs/String.h> 
#include <geometry_msgs/Quaternion.h> 
#include <geometry_msgs/PoseStamped.h> 
#include <tf/transform_broadcaster.h> 
#include <tf/tf.h>
#include "RefeLines.h"

main (int argc, char **argv) 
{ 
	ros::init (argc, argv, "testpath"); 

	ros::NodeHandle ph; 
	ros::Publisher path_pub = ph.advertise<nav_msgs::Path>("trajectory",1, true); 
     
	reference_line::RefLine reference_line;
	nav_msgs::Path ref_path = reference_line.generateRefLine_inRviz();

	ref_path.header.frame_id="world"; 

	ros::Rate loop_rate(1);
	while (ros::ok()) 
	{
		path_pub.publish(ref_path); 
		ros::spinOnce();  // check for incoming messages 

		loop_rate.sleep(); 
	} 

	return 0; 
}