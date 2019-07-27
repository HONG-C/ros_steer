cmake_minimum_required(VERSION 2.8.3)
project(ros_steer)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

add_message_files(
  FILES
  STEERING_MSG.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ros_steer
  CATKIN_DEPENDS message_generation roscpp std_msgs
  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(Keyboard_Steer src/Keyboard_Steer.cpp)
add_dependencies(Keyboard_Steer ${${PROJECT_NAME}_EXPORTED_TARGETS}
${catkin_EXPORTED_TARGETS})
target_link_libraries(Keyboard_Steer ${catkin_LIBRARIES})


add_executable(Steer_Servo src/Steer_Servo.cpp)
add_dependencies(Steer_Servo ${${PROJECT_NAME}_EXPORTED_TARGETS}
${catkin_EXPORTED_TARGETS})
target_link_libraries(Steer_Servo ${catkin_LIBRARIES})


add_executable(Keyboard_Servo src/Keyboard_Servo.cpp)
add_dependencies(Keyboard_Servo ${${PROJECT_NAME}_EXPORTED_TARGETS}
${catkin_EXPORTED_TARGETS})
target_link_libraries(Keyboard_Servo ${catkin_LIBRARIES})

