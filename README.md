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

sudo rosdep init
rosdep update
```


### PCL 설치
```bash
sudo apt install libpcl-dev
sudo apt-get install ros-humble-pcl-ros
sudo apt-get install ros-humble-pcl-conversions
sudo apt install pcl-tools
```

### gazebo 설치
https://gazebosim.org/docs/fortress/install_ubuntu/
https://docs.ros.org/en/humble/Tutorials/Advanced/Simulators/Gazebo/Gazebo.html
```bash
sudo apt-get update
sudo apt-get install lsb-release gnupg

sudo curl https://packages.osrfoundation.org/gazebo.gpg --output /usr/share/keyrings/pkgs-osrf-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/pkgs-osrf-archive-keyring.gpg] http://packages.osrfoundation.org/gazebo/ubuntu-stable $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/gazebo-stable.list > /dev/null
sudo apt-get update
sudo apt-get install ignition-fortress


sudo apt install gazebo
sudo apt install ros-humble-gazebo-ros
sudo apt install ros-humble-gazebo-ros-pkgs

sudo sh -c 'echo "deb http://packages.osrfoundation.org/gazebo/ubuntu-stable $(lsb_release -cs) main" > /etc/apt/sources.list.d/gazebo-stable.list'
wget https://packages.osrfoundation.org/gazebo.key -O - | sudo apt-key add -
sudo apt update
sudo apt install libgazebo-dev
sudo apt install libgazebo11

```


### turtlebot3 simulation 설치

```bash


```

### rtab 설치

```bash
sudo apt-get update
sudo apt-get install ros-humble-rtabmap-ros

git clone -b humble-devel  https://github.com/introlab/rtabmap_ros.git
git clone -b humble-devel  https://github.com/introlab/rtabmap.git
colcon build


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
- colcon build --executor sequential (에러가 나는 순차적으로 빌드 하는 방법)
- colcon build



## 실행
### 실행 하는 방법
- ros2 run point_cloud_processing pcd_import
- ros2 run point_cloud_processing plane_cloud
- ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py
- ros2 launch point_cloud_processing rtab_mapping.launch.py
- ros2 run teleop_twist_keyboard teleop_twist_keyboard

- pcl_viewer src/point_cloud_processing/point_clouds/plane_.pcd
- pcl_viewer -multiview 2 plane.pcd plane_.pcd

### ros2 사용법
- ros2 topic list
- ros2 topic echo /camera/camera_info


## rqt 설치
```
rqt의 주요 역할과 기능
rqt는 ROS에서 발생하는 이벤트나 데이터를 시각적으로 모니터링하고 관리할 수 있는 도구로, 다양한 플러그인을 통해 다양한 작업을 수행할 수 있습니다. 아래는 rqt에서 제공하는 주요 기능들입니다.

1. 토픽 및 메시지 모니터링
rqt_topic 플러그인은 ROS에서 퍼블리시되는 토픽과 메시지를 실시간으로 모니터링할 수 있게 해줍니다.
이를 통해 특정 센서나 노드가 올바른 데이터를 퍼블리시하고 있는지 쉽게 확인할 수 있습니다.
2. 노드 및 토픽 연결 상태 시각화
rqt_graph 플러그인을 사용하면 ROS 네트워크 내에서 노드와 토픽 간의 연결 관계를 그래프로 시각화할 수 있습니다.
이를 통해 노드들이 어떤 토픽을 퍼블리시하고 구독하는지 파악할 수 있습니다.
3. 이미지 시각화
rqt_image_view 플러그인은 이미지 토픽을 시각화하는 데 사용됩니다.
카메라 데이터나 영상 데이터를 실시간으로 확인하고 분석할 수 있습니다.
4. 동적 파라미터 조정
rqt_reconfigure 플러그인을 사용하여 ROS 노드의 파라미터를 실시간으로 조정할 수 있습니다.
이를 통해 시스템의 동작을 실시간으로 변경하고 테스트할 수 있습니다.
5. 로봇 제어
rqt_robot_steering 같은 플러그인을 사용하여 로봇을 수동으로 제어할 수 있습니다.
/cmd_vel과 같은 속도 명령 토픽을 퍼블리시하여 로봇을 직접 움직일 수 있습니다.
6. 로그 및 콘솔 관리
rqt_console 플러그인을 사용하여 ROS 로그 메시지를 실시간으로 모니터링하고, 발생하는 오류나 경고 메시지를 확인할 수 있습니다.
**rqt_logger_level**을 통해 각 노드의 로그 레벨을 동적으로 변경할 수 있습니다.
```