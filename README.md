# project_selfdriving


## Overview
This code find uses machine learning/DeepLearning (YOLO) to classify/tag different objects in the scene (persones, cars, etc) using images and pointclouds. 

Taging object is done using boundining boxes in the images and velodyne pointclouds, applications can be high level semanting segmentation combining both source.



This code have been tested under ROS Kinetic and Ubuntu 16.04. This is research code, expect that it changes often and any fitness for a particular purpose is disclaimed.

**Author: [Agustin Ortega](https://github.com/agusorte), aortega.jim@gmail.com**

![project_selfdriving example: video](project_selfdriving/doc/vel.mp4)


## Installation

dependences

- [ROS] (http://www.ros.org/) Kinect or bigger (this code was tested in with melodic and kinect)
- [YOLO](https://github.com/leggedrobotics/darknet_ros) 
	
- [PCL] (http://pointclouds.org/) (Point Cloud Library)
- [OpenCV](http://opencv.org/) (computer vision library),
- [boost](http://www.boost.org/) (Boost library),
- [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page) (Eigen)

## Building

### creating catkin space
we need to have a catkin space created, follow theses intructions to install catkin (see the link below):

http://wiki.ros.org/catkin/Tutorials/create_a_workspace

### YOLO


In order to install project_selfdriving we need to unzip the code.zip file to catkin_ws 

    cd catkin_workspace/src
    git clone --recursive https://github.com/leggedrobotics/darknet_ros/darknet_ros.git 
    
then build catking

	catkin_make -DCMAKE_BUILD_TYPE=Release

### Download weights for YOLO

The yolo-voc.weights and tiny-yolo-voc.weights are downloaded automatically in the CMakeLists.txt file. If you need to download them again, go into the weights folder and download the two pre-trained weights from the COCO data set:

And the pre-trained weight from YOLO v3 can be found here:

    wget http://pjreddie.com/media/files/yolov3-voc.weights
    wget http://pjreddie.com/media/files/yolov3.weights

### Project dowload and building

In order to install project_selfdriving we need to clone the repo 

    cd catkin_workspace/src
    git clone https://github.com/leggedrobotics/darknet_ros/darknet_ros.git
    
then build catking

   	catkin_make -DCMAKE_BUILD_TYPE=Release

## Download Datasets


## Nodes

### Node: project_selfdriving_node

This node connect YOLO and some BB algortihms for generating tags  

## Running nodes                   


## Setting

You want to test with your datasets then you need to modidy the following files inside of config/: ros.yalm, cam_calib.yalm, setting.yalm. These files contain all the topic read and written (publishes and subscribers).


you can modify camera calibration parameres using the follofing file:

	project_selfdriving/config/cam_calib.yalm

you can modify topics 

	project_velodyne/config/settings.yalm


## saving bounding boxes

All the date saved are in a kitti files that contains the bounding box associates with the images (2D) and pointclouds (3D)

kitty format file is saved in:

   	project_selfdriving/data/kitti_file.txt

# Final comments

Bounding box is creation is not perfect because:
- incomplete pointcloud,
- noisy points clouds
- small delay( YOLO runs in GPU 500 faster than PCL for projecting and generating bounbing boxes)

idea to solve this issue is to have a clustering to add the complete pointscloud 

Suggestion or comments email to Agustin Ortega aortega.jim@gmail.com
