cmake_minimum_required(VERSION 3.0.2)
project(light_ACK)

find_package(gazebo REQUIRED)

find_package(catkin REQUIRED COMPONENTS
  gazebo_ros
  roscpp
  std_msgs
)


add_message_files(
  FILES
  ack_respond.msg
)


catkin_package()

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")


add_executable(trans_gazebo src/trans_gazebo.cc)
target_link_libraries(trans_gazebo ${GAZEBO_LIBRARIES} pthread)
target_link_libraries(trans_gazebo ${catkin_LIBRARIES})

add_executable(pub_ack src/pub_ack.cc)
target_link_libraries(pub_ack ${GAZEBO_LIBRARIES})
target_link_libraries(pub_ack ${catkin_LIBRARIES})

add_executable(ack_mqtt src/ack_light.cc)
target_link_libraries(ack_mqtt ${catkin_LIBRARIES})
target_link_libraries(ack_mqtt ${GAZEBO_LIBRARIES})