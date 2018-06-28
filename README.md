# project_selfdriving


## Overview
This code find uses machine learning/DeepLearning (YOLO) to classify/tag different objects in the scene (persones, cars, etc) using images and pointclouds. 

Taging object is done using boundining boxes in the images and velodyne pointclouds, applications can be high level semanting segmentation combining both source.



This code have been tested under ROS Kinetic and Ubuntu 16.04. This is research code, expect that it changes often and any fitness for a particular purpose is disclaimed.

**Author: [Agustin Ortega](https://github.com/agusorte), aortega.jim@gmail.com**

### Installation

dependences
-[ROS] (http://www.ros.org/) Kinect or bigger (this code was tested in with melodic and kinect)
-[YOLO](https://github.com/leggedrobotics/darknet_ros) 
	
-[PCL]
- [OpenCV](http://opencv.org/) (computer vision library),
- [boost](http://www.boost.org/) (c++ library),
-Eigen

### Building

#### creating catkin space
we need to have a catkin space created, follow theses intructions to install catkin (see the link below):

http://wiki.ros.org/catkin/Tutorials/create_a_workspace

### YOLO


In order to install project_selfdriving we need to unzip the code.zip file to catkin_ws 

    cd catkin_workspace/src
    git clone --recursive https://github.com/leggedrobotics/darknet_ros/darknet_ros.git 
    
then build catking

$catkin_make -DCMAKE_BUILD_TYPE=Release

Running the ros node:

### Project

In order to install project_selfdriving we need to unzip the code.zip file to catkin_ws 

    cd catkin_workspace/src
    git clone https://github.com/leggedrobotics/darknet_ros/darknet_ros.git
    
then build catking

$catkin_make -DCMAKE_BUILD_TYPE=Release

Running the ros node:


# Setting

you can modify camera calibration parameres using the wollofing file

project_velodyne/config/cam_calib.yalm

you can modify topics 

project_velodyne/config/settings.yalm

kitti file

kitty format file is saved in:
project_velodyne/data/kitti_file.txt

# Final comments

Bounding box is creation is not perfect because:
- incomplete pointcloud,
- noisy points clouds
- small delay 

idea to solve this issue is to have a clustering to add the complete pointscloud 

Suggestion or comments email to Agustin Ortega aortega.jim@gmail.com
