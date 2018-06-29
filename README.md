# project_selfdriving


## Overview
This code uses machine learning/DeepLearning (YOLO) to classify/tag different objects in the scene (persones, cars, etc) using images and pointclouds. 

Taging object is done using boundining boxes in the images and velodyne pointclouds, applications can be used as high level semantic segmentation combining both sensor sources.



This code have been tested under ROS Kinetic and Ubuntu 16.04. This is research code, expect that it changes often and any fitness for a particular purpose is disclaimed.

**Author: [Agustin Ortega](https://github.com/agusorte), aortega.jim@gmail.com**

An Example of the results can be seen in this video

![project_selfdriving example: video](doc/vel.mp4)


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

### Compiling with ubuntu 18 and cuda 9.0

Yolo supports CUDA that accelerates 500 faster the processing but just supported with compilers smaller than version 6. To compile 

	catkin_make -DCMAKE_CXX_COMPILER=/usr/bin/g++-6 -DCMAKE_C_COMPILER=/usr/bin/gcc-6
	
	
### Download weights for YOLO

The yolo-voc.weights and tiny-yolo-voc.weights are downloaded automatically in the CMakeLists.txt file. If you need to download them again, go into the weights folder and download the two pre-trained weights from the COCO data set:

And the pre-trained weight from YOLO v3 can be found here:

    wget http://pjreddie.com/media/files/yolov3-voc.weights
    wget http://pjreddie.com/media/files/yolov3.weights

### Project_selfdriving download and building

In order to install project_selfdriving we need to clone the repo 

    cd catkin_workspace/src
    git clone https://github.com/agusorte/project_selfdriving
    
then build catking

   	catkin_make -DCMAKE_BUILD_TYPE=Release

## Download Datasets

### Velodyne rosbag 

Be sure the rosbag is in the folder data using this link:

	https://drive.google.com/open?id=1M1NiVaHe-pgANQJEKGTwpz1lIqa8pmvS

create a folder data and move there
	
	mv _2017-12-06-20-02-29_Cam0Fltrd_VLP32C_Mall_Clockwise.bag data

	

### kitti dataset (Experimental)

Unfortunally this code uses rosbags as input, you can create your own robag data for using kitti dataset:
-  [KITTI](https://github.com/tomas789/kitti2bag)

you can dowload an experimental rosbag from https://drive.google.com/open?id=1mvqgxkxeChT6zgVS-9zdf6FKEZmM_VTg

copy to the folder data

	mv kitti_2011_09_26_drive_0084_synced.bag data

## Running program using ROS launch

for running the example using the rosbag velodyne


	roslaunch project_selfdriving project_selfdriving.launch

for runing the example using the kitti dataset
	
	roslaunch project_selfdriving  project_Selfdriving_kitti.launch 

**NOTE: both programs runs rviz to visualize results, please be sure you have it install it.


## Nodes

### Node: project_selfdriving_node

This node connect YOLO and some BB algortihms for generating tags  

## Running nodes                   


## Setting

You want to test with your datasets then you need to modidy the following files inside of config/: ros.yalm, cam_calib.yalm, setting.yalm. These files contain all the topic read and written (publishes and subscribers).


you can modify camera calibration parameres using the following file:

	project_selfdriving/config/cam_calib.yalm

you can modify topics (publishers and subscribers)

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
