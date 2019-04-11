/*
This program is used for the control of a DC motor by publishing distance values on a 
topic at the same time listening to the string coming from arduino board.
*/


#include "ros/ros.h"
#include "std_msgs/UInt16.h"
#include "std_msgs/Float32.h"
#include "std_msgs/String.h"
#include <unistd.h>

#include <sstream>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
std_msgs::Float32 force_msg;



/*void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}*/

void forceCallback(const std_msgs::Float32& msg)
{
  force_msg.data = msg.data;
  cout << " " << msg.data << endl;
  ROS_INFO("I heard: [%f]", msg.data);
}


float polyfit(float id) {
	// With intercept
	std::vector<float> coeffs {-5.50862555e6, 2.87482098e6, -5.62239443e5, 4.88409188e4, -1.59000778e3};

	// Without intercept
	// std::vector<float> coeffs {-5.50862555e6, 2.87482098e6, -5.62239443e5, 4.88409188e4, -1.59000778e3};

	float poly = 0;
	for (int i = 0; i < 5; i++) {
		poly += coeffs[i] * pow(id, 5-1-i);
	}
	return poly;
}

int main(int argc, char **argv)
{
	ofstream outputFile;
	outputFile.open("/home/isabella/catkin_ws/logs/force_matching_small_log.txt", std::ios_base::app);


	ros::init(argc, argv, "dis_node");
	ros::NodeHandle n;
	ros::Publisher disPub = n.advertise<std_msgs::Float32>("dis_signal", 1000);

	ros::Rate loop_rate(2);

	std_msgs::Float32 desired_deflection;
	std_msgs::Float32 signal;

	desired_deflection.data = atof(argv[1]);
	float desired_force = atof(argv[2]);
	cout << "Desired initial deflection is (m) : " << desired_deflection.data << endl;

	loop_rate.sleep();

	float dist_travelled = 0;


	std_msgs::Float32 force_msg;
	std_msgs::Float32 deflection_msg;
	force_msg = *(ros::topic::waitForMessage<std_msgs::Float32>("/forcesensor", n));
	deflection_msg = *(ros::topic::waitForMessage<std_msgs::Float32>("/deflection", n));


	// Wait until the deflection is just right for our initial pressure state
	while (deflection_msg.data - desired_deflection.data > 0.001) {
		deflection_msg = *(ros::topic::waitForMessage<std_msgs::Float32>("/deflection", n));
	} 


	// First get slope characteristics
	cout << "Initial deflection: " << deflection_msg.data << endl;
	float slope = polyfit(deflection_msg.data);
	cout << "Slope: " << slope << endl;

	// Then get desired deflection
	float delta_d = (desired_force / slope) / 1000;

	float deflection_goal = deflection_msg.data - delta_d;
	cout << "Desired deflection: " << deflection_goal << endl;


	// CONTROL LOOP -- FORCE MATCHING
	
	float error = 10;
	float kp = 500.0;
	while (abs(error) > 0.001) {

		force_msg = *(ros::topic::waitForMessage<std_msgs::Float32>("/forcesensor", n));
		deflection_msg = *(ros::topic::waitForMessage<std_msgs::Float32>("/deflection", n));

		error = deflection_msg.data - deflection_goal;
		// cout << "Deflection: " << deflection_msg.data << " -- Error: " << error << endl;
		// cout << dist_travelled << ", " << force_msg.data << endl;


		// How much to move forward (in mm) depends on the error
		signal.data = kp * error;
		// cout << "Go forward: " << signal.data << " mm " << std::endl;
		disPub.publish(signal);
		dist_travelled += signal.data;


		ros::spinOnce();
		ros::Duration(1).sleep();
	}

	ros::Duration(1).sleep();

	force_msg = *(ros::topic::waitForMessage<std_msgs::Float32>("/forcesensor", n));
	deflection_msg = *(ros::topic::waitForMessage<std_msgs::Float32>("/deflection", n));
	cout << "FINAL DEFLECTION AND FORCE " << deflection_msg.data << ", " << force_msg.data * 0.0098 << endl;

	// FORCE GRAPH

	// outputFile.open("/home/isabella/catkin_ws/logs/force_deflection_log.txt", std::ios_base::app);
	outputFile << desired_deflection.data << ", " << desired_force << ", " << deflection_msg.data << ", " << force_msg.data * 0.0098 << endl;

	/*
	float step_size = 1;
	while (dist_travelled < 24) {
		std_msgs::Float32 force_msg;
		std_msgs::Float32 deflection_msg;
		force_msg = *(ros::topic::waitForMessage<std_msgs::Float32>("/forcesensor", n));
		deflection_msg = *(ros::topic::waitForMessage<std_msgs::Float32>("/deflection", n));

		cout << dist_travelled << ", " << force_msg.data << ", " << deflection_msg.data <<  endl;
		outputFile << dist_travelled << ", " << force_msg.data << ", " << deflection_msg.data << endl;

		// How much to move forward (in mm) depends on the error
		signal.data = step_size;
		disPub.publish(signal);
		dist_travelled += signal.data;


		ros::spinOnce();
		ros::Duration(0.5).sleep();
	}
	*/

	// signal.data = desired_deflection.data;
	// disPub.publish(signal);
	// dist_travelled += signal.data;


	// ros::spinOnce();
	// ros::Duration(0.2).sleep();
	// for (int k = 0; k < 5; k ++) {


	// 	std_msgs::Float32 force_msg;
	// 	std_msgs::Float32 deflection_msg;
	// 	force_msg = *(ros::topic::waitForMessage<std_msgs::Float32>("/forcesensor", n));
	// 	deflection_msg = *(ros::topic::waitForMessage<std_msgs::Float32>("/deflection", n));

	// 	cout << dist_travelled << ", " << force_msg.data << ", " << deflection_msg.data <<  endl;
	// 	outputFile << desired_deflection.data << ", " << force_msg.data << ", " << deflection_msg.data << endl;


	// }



	outputFile.close();

	ros::Duration(2).sleep();
	signal.data = -1.0* dist_travelled;
	disPub.publish(signal);
	ros::spinOnce();
	ros::Duration(2).sleep();

	cout << "Back to start" << endl;
	



	ROS_INFO("Testing completed.");

	return 0;
}