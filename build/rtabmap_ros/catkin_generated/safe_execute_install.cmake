execute_process(COMMAND "/home/cmartin/Desktop/Udacity/Robotics/C4/P4/build/rtabmap_ros/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/cmartin/Desktop/Udacity/Robotics/C4/P4/build/rtabmap_ros/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
