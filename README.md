# PCL 학습
- udemy 기반으로 학습. 하나씩 따라해봄

## 설치
### ROS humble 설치
### 세팅


- source /opt/ros/humble/local_setup.bash
- source /opt/ros/humble/setup.bash
- ros2 pkg create --build-type ament_cmake point_cloud_processing


### 추가 설치
- https://github.com/ROBOTIS-GIT/turtlebot3
- sudo apt install pcl-tools

- pcl_viewer src/point_cloud_processing/point_clouds/plane_.pcd
- pcl_viewer -multiview 2 plane.pcd plane_.pcd
- gazebo 설치



## 빌드
### 빌드 하는 방법
- colcon build --packages-select point_cloud_processing
- colcon build



## 실행
### 실행 하는 방법
- ros2 run point_cloud_processing pcd_import
- ros2 run point_cloud_processing plane_cloud
- ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py