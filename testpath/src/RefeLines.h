//
// Created by fhz on 2020/3/30.
// 测试Ros中通过导入节点外程序

#ifndef RefeLines_H
#define RefeLines_H

#include <iostream>
#include <nav_msgs/Path.h> 
#include <std_msgs/String.h> 
#include <geometry_msgs/Quaternion.h> 
#include <geometry_msgs/PoseStamped.h> 

namespace reference_line{


/**
    通过rviz可视化显示参考线
*/

class RefLine
{
public:
    nav_msgs::Path generateRefLine_inRviz();
};



}
#endif