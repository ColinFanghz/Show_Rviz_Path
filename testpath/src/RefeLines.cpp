//
// Created by fhz on 2020/3/30.
// 测试Ros中通过导入节点外程序

#include "RefeLines.h"

namespace reference_line
{

/**
 通过rviz可视化显示参考线
*/
nav_msgs::Path RefLine::generateRefLine_inRviz()
{
    nav_msgs::Path PathLine;
    geometry_msgs::PoseStamped p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13;

	p1.pose.position.x = 0.0; 
	p1.pose.position.y = 0.0;
	p2.pose.position.x = 20.0; 
	p2.pose.position.y = 0.0;
	p3.pose.position.x = 50.0; 
	p3.pose.position.y = 0.0;
	p4.pose.position.x = 100.0; 
	p4.pose.position.y = 0.0;
	p5.pose.position.x = 150.0; 
	p5.pose.position.y = 0.0;

	p6.pose.position.x = 220.0; 
	p6.pose.position.y = 50.0;
	p7.pose.position.x = 220.0; 
	p7.pose.position.y = 100.0;
	p8.pose.position.x = 220.0; 
	p8.pose.position.y = 150.0;
	p9.pose.position.x = 220.0; 
	p9.pose.position.y = 200.0;
	p10.pose.position.x = 220.0; 
	p10.pose.position.y = 250.0;

    PathLine.poses.push_back(p1);
	PathLine.poses.push_back(p2);
	PathLine.poses.push_back(p3);
	PathLine.poses.push_back(p4);
	PathLine.poses.push_back(p5);
	PathLine.poses.push_back(p6);
	PathLine.poses.push_back(p7);
	PathLine.poses.push_back(p8);
	PathLine.poses.push_back(p9);
	PathLine.poses.push_back(p10);
	
    return PathLine;
}



} //namespace reference_line