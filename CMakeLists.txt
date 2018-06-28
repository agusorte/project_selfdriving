cmake_minimum_required(VERSION 2.8.3)
project(project_selfdriving)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

# Set c++11 cmake flags
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  cv_bridge
  sensor_msgs
  rosboost_cfg
  pcl_conversions
  pcl_ros
  message_filters
  darknet_ros_msgs

)
#find_package(PCL REQUIRED)
find_package(Boost REQUIRED)

find_package(OpenCV REQUIRED)



###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS 
  include
  LIBRARIES
  ${PROJECT_NAME}_lib
  CATKIN_DEPENDS 
  cv_bridge 
  roscpp 
  rospy 
  std_msgs
  pcl_conversions
  pcl_ros
  sensor_msgs
  rosboost_cfg
  darknet_ros_msgs
  DEPENDS Boost
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${PROJECT_NAME}/include
  ${PROJECT_NAME}/src
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${OpenCV_LIBRARIES}
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/project_velodyne.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
#add_dependencies(${PROJECT_NAME}_lib ${catkin_EXPORTED_TARGETS})

add_library(${PROJECT_NAME}_lib
	 src/projectSelfdriving.cpp
	)

target_link_libraries(${PROJECT_NAME}_lib
	 ${OpenCV_LIBRARIES}
     ${catkin_LIBRARIES}
     ${Boost_LIBRARIES}
     ${OpenCV_LIBRARIES}
     )
## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
add_executable(${PROJECT_NAME}_node src/project_selfdriving_node.cpp)

## Rename C++ executable without prefix
## The above recommended prefix causes long target names, the following renames the
## target back to the shorter version for ease of user use
## e.g. "rosrun someones_pkg node" instead of "rosrun someones_pkg someones_pkg_node"
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(${PROJECT_NAME}_node  ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}_node
   ${catkin_LIBRARIES}
    ${OpenCV_LIBRARIES}
    ${catkin_LIBRARIES}
    ${PROJECT_NAME}_lib
    #${PCL_LIBRARIES}
    ${Boost_LIBRARIES}
 )
