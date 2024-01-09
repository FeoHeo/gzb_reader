cmake_minimum_required(VERSION 3.0.2)
project(reader)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  gazebo_plugins
  gazebo_ros
  roscpp
)

catkin_package()

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(light_code_reader src/light_code_reader.cc)
target_link_libraries(light_code_reader ${catkin_LIBRARIES})
install(TARGETS light_code_reader
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})