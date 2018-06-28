/*
 * project_velodyne_node.cpp
 *
 *  Created on: Feb, 2018
 *  Author: Agustin Ortega 
 *  Email: aortega.jim@gmail.com
 */

#include <ros/ros.h>
#include "project_selfdriving/projectSelfdriving.hpp"

int main(int argc, char** argv) {

  ros::init(argc, argv, "project_selfdriving_node");
  ros::NodeHandle nodeHandle("~");
  
  // we start our node
  project_selfdriving::ProjectSelfdriving projectselfdriving(nodeHandle);

  ros::spin();
  return 0;
}
