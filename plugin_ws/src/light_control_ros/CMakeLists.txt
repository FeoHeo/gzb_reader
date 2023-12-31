cmake_minimum_required(VERSION 3.0.2)
project(light_control_ros)

find_package(gazebo REQUIRED)    #for gazebo plugins

find_package(catkin REQUIRED COMPONENTS
  gazebo_plugins                    #for gazebo plugins
  gazebo_ros                        #for gazebo ros plugins
  roscpp
)


catkin_package()
  
include_directories(
  ${catkin_INCLUDE_DIRS}
)

# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE)

#for gazebo plugins
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

add_library(lightcontroller_ros_plugin SHARED src/lightcontroller_ros_plugin.cc)
target_link_libraries(lightcontroller_ros_plugin ${GAZEBO_LIBRARIES})


add_library(simple_lightcontroller_ros_plugin SHARED src/simple_lightcontroller_ros_plugin.cc)
target_link_libraries(simple_lightcontroller_ros_plugin ${GAZEBO_LIBRARIES})

add_library(lightName_reader_plugin SHARED src/lightCodeReader.cc)
target_link_libraries(lightName_reader_plugin ${GAZEBO_LIBRARIES})