//
// Created by fhz on 2020/3/27.
//

#include <ros/ros.h> 
#include <ros/console.h> 
#include <nav_msgs/Path.h> 
#include <std_msgs/String.h> 
#include <geometry_msgs/Quaternion.h> 
#include <geometry_msgs/PoseStamped.h> 
#include <tf/transform_broadcaster.h> 
#include <tf/tf.h>
//#include "RefeLines.h"

#include <pcl/point_cloud.h> 
#include <pcl_conversions/pcl_conversions.h> 
#include <sensor_msgs/PointCloud2.h> 

main (int argc, char **argv) 
{ 
	ros::init (argc, argv, "showpath"); 

	ros::NodeHandle ph; 
	ros::Publisher path_pub = ph.advertise<nav_msgs::Path>("trajectory",1, true); 
//
	ros::Publisher pcl_pub = ph.advertise<sensor_msgs::PointCloud2> ("pcl_output", 1); 
	ros::Publisher pcl_pub1 = ph.advertise<sensor_msgs::PointCloud2> ("pcl_output1", 1); 
 
	pcl::PointCloud<pcl::PointXYZ> cloud; 
	pcl::PointCloud<pcl::PointXYZ> cloud1;

	sensor_msgs::PointCloud2 output;
	sensor_msgs::PointCloud2 output1;

	cloud.width = 100; 
	cloud.height = 1; 
	cloud.points.resize(cloud.width * cloud.height); 

	cloud1.width = 100; 
	cloud1.height = 1; 
	cloud1.points.resize(cloud1.width * cloud1.height);

		for (size_t i = 0; i < 26; ++i)
	 {
		if (i<8)
		{
      	 cloud.points[i].x = 0.1*i; 
		 cloud.points[i].y = 0.3; 

		 cloud1.points[i].x = 0.1*i; 
		 cloud1.points[i].y = -0.3;
		}
		else if(i<13)
		{
		 cloud.points[i].x = 0.7; 
		 cloud.points[i].y = 0.3+0.1*(i-7); 

		 cloud1.points[i].x = 0.1*i; 
		 cloud1.points[i].y = -0.3;
		}
		else
		{
		 cloud.points[i].x = 0.7;
		 cloud.points[i].y = 0.8+0.1*(i-12);

		 cloud1.points[i].x = 1.3; 
		 cloud1.points[i].y = -0.3+0.1*(i-12);
		}
         /** 
		 cloud.points[i].x = 1024 * rand () / (RAND_MAX + 1.0f); 
		 cloud.points[i].y = 1024 * rand () / (RAND_MAX + 1.0f); 
		 cloud.points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);
         **/ 
	} 

	pcl::toROSMsg(cloud, output);
	pcl::toROSMsg(cloud1, output1);

	output.header.frame_id="world"; 
	output1.header.frame_id = "world";
//

	ros::Time current_time, last_time; 
	current_time = ros::Time::now(); 
	last_time = ros::Time::now(); 

	nav_msgs::Path path; 
	//nav_msgs::Path path; 
	path.header.stamp=current_time; 
	path.header.frame_id="world"; 


    //2维运动的三自由度量

	int flag = 0;           //标志位，用来控制循环的次数

	ros::Rate loop_rate(1); 
	while (ros::ok()) 
	{
		/** 
		current_time = ros::Time::now(); 
		compute odometry in a typical way given the velocities of the robot 
		double dt = (current_time - last_time).toSec(); 
		double delta_x = (vx * cos(th) - vy * sin(th)) * dt; 
		double delta_y = (vx * sin(th) + vy * cos(th)) * dt; 
		double delta_th = vth * dt; 

		x += delta_x; 
		y += delta_y; 
		th += delta_th; 

		geometry_msgs::PoseStamped this_pose_stamped; 
		this_pose_stamped.pose.position.x = x; 
		this_pose_stamped.pose.position.y = y; 
		**/

		/**
		geometry_msgs::Quaternion goal_quat = tf::createQuaternionMsgFromYaw(th); 
		this_pose_stamped.pose.orientation.x = goal_quat.x; 
		this_pose_stamped.pose.orientation.y = goal_quat.y; 
		this_pose_stamped.pose.orientation.z = goal_quat.z; 
		this_pose_stamped.pose.orientation.w = goal_quat.w; 
		**/

		double x = 0.0;      //初始的x起点
		double y = 0.0;      //初始的y起点
		double th = 0.0;     //初始的角度
		double vx = 0.1;     //初始的x轴向速度
		double vy = 0.1;     //初始的y轴向速度
		double vth = 0;      //初始的角速度
		
		if(flag == 0)
		{
			// 用for循环生成路点
			// 这里用的随i变化所生成的
			
			for (size_t i = 0; i < 15; i++){
		//		vx = calPath(vx);
		//		vy = calPath(vy);

				if (i<5)
				{
					double delta_x = 0.1;
					x += delta_x; 
				}
				else if (i<10)
				{
					double delta_x = 0.1;
					double delta_y = 0.1;

					x += delta_x;
					y += delta_y;
				}
				else
				{
					double delta_y = 0.1;
					y += delta_y;
				}

				geometry_msgs::PoseStamped this_pose_stamped; 
				this_pose_stamped.pose.position.x = x; 
				this_pose_stamped.pose.position.y = y;

				this_pose_stamped.header.frame_id="world"; 
				path.poses.push_back(this_pose_stamped);
			}

			/**

			for (size_t i = 0; i < 5; i++)
			{
				geometry_msgs::PoseStamped this_pose_stamped; 
				this_pose_stamped.pose.position.x = GetValueX(i); 
				this_pose_stamped.pose.position.y = GetValueY(i);

				this_pose_stamped.header.frame_id="world"; 
				path.poses.push_back(this_pose_stamped);
			}
			**/

		 	flag = 1;
		}

		//this_pose_stamped.header.stamp=current_time; 
		//this_pose_stamped.header.frame_id="world"; 
		//path.poses.push_back(this_pose_stamped); 

		pcl_pub.publish(output);
		pcl_pub1.publish(output1);

		path_pub.publish(path); 
		ros::spinOnce();  // check for incoming messages 

		//last_time = current_time; 
		loop_rate.sleep(); 
	} 
	return 0; 
}