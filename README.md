# PCL 학습
- udemy 기반으로 학습. 하나씩 따라해봄


## 참고 사이트
https://github.com/noshluk2/ROS2-Point-Cloud-Clustering-and-Segmentation-for-Autonomous-Behaviour
https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html
https://robotisim.com/developing-in-ros2-for-begginers/
https://robotisim.com/ros2-cpp-node-for-begginers/
https://github.com/introlab/rtabmap_ros/tree/humble-devel/rtabmap_demos/launch

## 설치
### ROS humble 설치
```bash
locale  # check for UTF-8

sudo apt update && sudo apt install locales
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8

locale  # verify settings


sudo apt install software-properties-common
sudo add-apt-repository universe


sudo apt update && sudo apt install curl -y
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg

echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

sudo apt update
sudo apt upgrade
sudo apt install ros-humble-desktop
sudo apt install ros-humble-ros-base

sudo apt install ros-dev-tools
```


### PCL 설치
```bash
sudo apt install libpcl-dev
sudo apt-get install ros-humble-pcl-ros
sudo apt-get install ros-humble-pcl-conversions
sudo apt install pcl-tools
```


### turtlebot3 simulation 설치
```bash


```

## 세팅

### ros 세팅
- ros2 pkg create --build-type ament_cmake point_cloud_processing


### 추가 설치
- https://github.com/ROBOTIS-GIT/turtlebot3
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

- pcl_viewer src/point_cloud_processing/point_clouds/plane_.pcd
- pcl_viewer -multiview 2 plane.pcd plane_.pcd