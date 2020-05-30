//
// Created by fhz on 2020/3/30.
// 测试Ros中通过导入节点外程序

#include <Eigen/Dense>
#include "RefeLines.h"
#include <fstream>
#include <geometry_msgs/Point.h>
#include <tf/transform_datatypes.h>
#include <istream>
#include <iostream>
#include <iomanip>

namespace reference_line
{

RefLine::RefLine()
{
    std::vector<double> waypoints_x={{0.0, 20.0, 50, 100.0, 150.0, 220.0, 300.0, 350.0, 400.0, 430.0, 370.0, 300, 200.0}};
    std::vector<double> waypoints_y={{0.0, 70.0, 100, 120.0, 120.0, 150.0, 180.0, 150.0, 110.0, 20.0, -80.0, -80.0, -80.0}};

    std::vector<double> x = waypoints_x;
    std::vector<double> y = waypoints_y;
    std::vector<double> r_x, r_y;

}


// 通过rviz可视化显示参考线
nav_msgs::Path RefLine::generateRefLine_inRviz()
{
    refline_waypoints_.header.stamp=ros::Time::now();
    refline_waypoints_.header.frame_id="/world";

    for(double i=0; i<13; i++)
    {
        r_x.push_back(x[i]);
        r_y.push_back(y[i]);

        geometry_msgs::PoseStamped this_pose_stamped; 
		this_pose_stamped.pose.position.x = x; 
		this_pose_stamped.pose.position.y = y;

        path.poses.push_back(this_pose_stamped);

    }

    return refline_waypoints_;
}

} //namespace reference_line