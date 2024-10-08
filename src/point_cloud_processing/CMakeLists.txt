cmake_minimum_required(VERSION 3.8)
project(point_cloud_processing)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


find_package(ament_cmake REQUIRED)
find_package(PCL REQUIRED)


include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})


add_executable(pcd_import src/0_table_scene.cpp)
target_link_libraries(pcd_import ${PCL_LIBRARIES})

add_executable(plane_cloud src/1_planner_cloud.cpp)
target_link_libraries(plane_cloud ${PCL_LIBRARIES})

add_executable(circular_cloud src/2_circular_cloud.cpp)
target_link_libraries(circular_cloud ${PCL_LIBRARIES})

install(TARGETS
  pcd_import
  plane_cloud
  circular_cloud
  DESTINATION lib/${PROJECT_NAME})


install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

# install(DIRECTORY
#   launch
#   rviz
#   DESTINATION share/${PROJECT_NAME}/
# )

# /home/chovy/workspace-ros/pcl-exercise/src/point_cloud_processing/launch/rtab_mapping.launch.py
# install(
#   PROGRAMS
#   launch/rtab_mapping.launch.py
#   DESTINATION lib/${PROJECT_NAME}/
# )


# install(TARGETS
#   pcd_import plane_cloud circular_cloud filtering_segmentation  path_creation kitti_voxel kd_tree traffic_segmentation
#   DESTINATION lib/${PROJECT_NAME})

# install(DIRECTORY
#   launch
#   rviz
#   DESTINATION share/${PROJECT_NAME}/
# )

ament_package()
