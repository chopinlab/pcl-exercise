#include <iostream>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/voxel_grid.h>
#include <filesystem>

int main() {

    pcl::PointCloud<pcl::PointXYZ> cloud;

    cloud.push_back(pcl::PointXYZ(1.0, 2.0, 3.0));

    // std::string path = "/home/luqman/ros2_ws/src/ROS2-Point-Cloud-Clustering-and-Segmentation-for-Autonomous-Behaviour/point_cloud_processing/point_clouds/plane_.pcd";

    std::string pcd_file_name = "plane_.pcd";
	std::filesystem::path current_path    = std::filesystem::current_path();
    std::filesystem::path point_cloud_dir = current_path/"src/point_cloud_processing/point_clouds/";
    std::string pcd_file_path             = point_cloud_dir/pcd_file_name;
    pcl::io::savePCDFileASCII(pcd_file_path, cloud);
    std::cout<<cloud.size();

    return 0;
}