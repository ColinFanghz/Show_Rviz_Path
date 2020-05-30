//
// Created by fhz on 2020/3/30.
// 测试Ros中通过导入节点外程序

#ifndef RefeLines_H
#define RefeLines_H

#include <iostream>
#include <vector>
#include <array>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>

namespace reference_line{

class RefLine
{
public:
    RefLine();

    /**
     * 通过rviz可视化显示参考线
     */
    nav_msgs::Path generateRefLine_inRviz();

};

}
#endif