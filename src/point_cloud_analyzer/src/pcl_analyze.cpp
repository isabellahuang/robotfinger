#include <ros/ros.h>
#include <pcl/point_types.h>
#include <boost/foreach.hpp>
#include <math.h>

#include <iostream>
#include <pcl_ros/point_cloud.h>
#include <boost/thread/thread.hpp>
#include <pcl/common/common_headers.h>
#include <pcl/features/normal_3d.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/common/common.h>
#include <pcl/filters/voxel_grid.h>

#include <pcl/console/parse.h>

typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;
boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;

bool SAVED = false;

boost::shared_ptr<pcl::visualization::PCLVisualizer> simpleVis (pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr cloud)
{
  // --------------------------------------------
  // -----Open 3D viewer and add point cloud-----
  // --------------------------------------------
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
	viewer->setBackgroundColor (0, 0, 0);
	viewer->addPointCloud<pcl::PointXYZRGB> (cloud, "cloud");
	viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud");
	// viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_LUT, pcl::visualization::PCL_VISUALIZER_LUT_JET, "cloud");
	viewer->addCoordinateSystem (1.0);
	viewer->initCameraParameters ();
	viewer->removeCoordinateSystem();
	return (viewer);
}

uint32_t getRGB(double z) {
	double min_z = 0.018; //0.06;
	double max_z = 0.037;//0.09;
	double f = (z - min_z) / (max_z - min_z);

	if (f > 1) {
		f = 1.0;
	}


	double a = (1-f)/0.2;
	double X = floor(a);
	double Y = floor(255*(a-X));

	// std::cout << z << " " << X << " " << Y << std::endl;
	int r = 0;
	int g = 0;
	int b = 0;
	switch((int) X) {
		case 0: r=255; g=Y; b=0; break;
		case 1: r=255 - Y; g=255; b=0; break;
		case 2: r=0; g=255; b=Y;break;
		case 3: r=0; g=255 - Y; b=255;break;
		case 4: r=Y; g=0; b=255;break;
		case 5: r=255; g=0; b=255; break;
	}

	// std::cout << r << " " << g << " " << b << std::endl;
	uint32_t rgb = ((uint32_t) r << 16 | (uint32_t)g << 8 | (uint32_t) b);	
	return rgb;
}


void callback(const PointCloud::ConstPtr& msg)
{
	// printf ("Cloud: width = %d, height = %d\n", msg->width, msg->height);
	// std::cout << msg->points.size() << std::endl;
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_display (new pcl::PointCloud<pcl::PointXYZRGB>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_display_basic (new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr downsampled_msg (new pcl::PointCloud<pcl::PointXYZ>);

	// Downsample
	pcl::VoxelGrid<pcl::PointXYZ> sor;
	sor.setInputCloud(msg);
	sor.setLeafSize(0.005f, 0.005f, 0.005f);
	sor.filter(*downsampled_msg);
	


	float mindistcenter = 9999;
	float centerdepth = 0;

	float minz = 99999;
	float maxz = 0;
	float minradius3d = 9999;
	float maxradius3d = 0;
	float minRadius = 9999;
  	BOOST_FOREACH (const pcl::PointXYZ& pt, downsampled_msg->points) {

  		if (std::isnan(pt.x) || std::isnan(pt.y) || std::isnan(pt.z)) {
  			continue;
  		}

  		// printf ("\t(%f, %f, %f)\n", pt.x, pt.y, pt.z);
  		pcl::PointXYZRGB point;
  		pcl::PointXYZ point_basic;

  		point.x = pt.x;
  		point.y = pt.y;
  		point.z = pt.z;

   		point_basic.x = pt.x;
  		point_basic.y = pt.y;
  		point_basic.z = pt.z;


  		if (point.z < minz) {
  			minz = point.z;
  		}

  		if (point.z > maxz) {
  			maxz = point.z;
  		}


  		float radius = sqrt(pt.x*pt.x + pt.y*pt.y);
  		if (radius < minRadius) {
  			minRadius = radius;
  		}

  		// if (radius < 0.022) {
  		if (radius < 0.022) {
  		 	float radius3d = sqrt(pt.x*pt.x + pt.y*pt.y + (pt.z-0.06)*(pt.z-0.06));
  		 	if (radius3d > maxradius3d) {
  		 		maxradius3d = radius3d;
  		 	}

  		 	if (radius3d < minradius3d) {
  		 		minradius3d = radius3d;
  		 	}


  		 	// Default red
	   		uint8_t r = 255, g = 0;
	  		uint8_t b = 0;
	  		uint32_t rgb = ((uint32_t) r << 16 | (uint32_t)g << 8 | (uint32_t)b);	 		


  		 	if (radius3d > 0.02) {
  		 		// Make it green
		   		r = 0;
		   		g = 255;
		  		b = 0;
		  		rgb = ((uint32_t) r << 16 | (uint32_t)g << 8 | (uint32_t)b);
  		 	}

  		 	if (radius < mindistcenter) {
  		 		mindistcenter = radius;
  		 		centerdepth = pt.z;
  		 	}


	   		// uint32_t rgb = getRGB(radius3d);
	  		point.rgb = *reinterpret_cast<float*>(&rgb);
  			cloud_display->points.push_back(point);
  			cloud_display_basic->points.push_back(point_basic);
  		}
  	}


  	// std::cout << minRadius << std::endl;
  	// std::cout << minradius3d << " " <<  maxradius3d << std::endl;
  	std::cout << centerdepth << std::endl;
  	// std::cout << minz << " " << maxz << std::endl;


  // ----------------------------------------------------------------
  // -----Calculate surface normals with a search radius of 0.05-----
  // ----------------------------------------------------------------
	// pcl::NormalEstimation<pcl::PointXYZRGB, pcl::Normal> ne;
	// ne.setInputCloud (cloud_display);
	// pcl::search::KdTree<pcl::PointXYZRGB>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZRGB> ());
	// ne.setSearchMethod (tree);
	// pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);
	// ne.setRadiusSearch (0.01);
	// ne.compute (*cloud_normals);

	cloud_display->width = (int) cloud_display->points.size ();
	cloud_display->height = 1;
	cloud_display_basic->width = (int) cloud_display_basic->points.size ();
	cloud_display_basic->height = 1;

	if (!SAVED) {
		pcl::io::savePCDFileASCII("deformed.pcd", *cloud_display_basic);
		SAVED = true;
	}

	viewer->updatePointCloud(cloud_display);


	// viewer->removePointCloud("normals", 0);
	// viewer->addPointCloudNormals<pcl::PointXYZRGB, pcl::Normal> (cloud_display, cloud_normals, 10, 0.05, "normals");

}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "sub_pcl");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe<PointCloud>("/royale_camera_driver/point_cloud", 1, callback);



  // ------------------------------------
  // -----Create example point cloud-----
  // ------------------------------------
	pcl::PointCloud<pcl::PointXYZ>::Ptr basic_cloud_ptr (new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr point_cloud_ptr (new pcl::PointCloud<pcl::PointXYZRGB>);
	std::cout << "Genarating example point clouds.\n\n";
  // We're going to make an ellipse extruded along the z-axis. The colour for
  // the XYZRGB cloud will gradually go from red to green to blue.
	uint8_t r(255), g(15), b(15);
	for (float z(-1.0); z <= 1.0; z += 0.05)
	{
		for (float angle(0.0); angle <= 360.0; angle += 5.0)
		{
			pcl::PointXYZ basic_point;
			basic_point.x = 0.5 * cosf (pcl::deg2rad(angle));
			basic_point.y = sinf (pcl::deg2rad(angle));
			basic_point.z = z;
			basic_cloud_ptr->points.push_back(basic_point);

			pcl::PointXYZRGB point;
			point.x = basic_point.x;
			point.y = basic_point.y;
			point.z = basic_point.z;
			uint32_t rgb = (static_cast<uint32_t>(r) << 16 |
				static_cast<uint32_t>(g) << 8 | static_cast<uint32_t>(b));
			point.rgb = *reinterpret_cast<float*>(&rgb);
			point_cloud_ptr->points.push_back (point);
		}
		if (z < 0.0)
		{
			r -= 12;
			g += 12;
		}
		else
		{
			g -= 12;
			b += 12;
		}
	}
	basic_cloud_ptr->width = (int) basic_cloud_ptr->points.size ();
	basic_cloud_ptr->height = 1;
	point_cloud_ptr->width = (int) point_cloud_ptr->points.size ();
	point_cloud_ptr->height = 1;
	viewer = simpleVis(point_cloud_ptr);


	while (!viewer->wasStopped ())
	{
		viewer->spinOnce (100);
		boost::this_thread::sleep (boost::posix_time::microseconds (100000));
		// sleep(1);
		ros::spinOnce();
	}


}
