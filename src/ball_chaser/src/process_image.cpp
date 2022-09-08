#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>
#include <math.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // TODO: Request a service and pass the velocities to it to drive the robot

    ROS_INFO_STREAM("Calling service DriveToTarget...");

    // Request centered joint angles [1.57, 1.57]
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    // Call the safe_move service and pass the requested joint angles
    if (!client.call(srv))
        ROS_ERROR("Failed to call service DriveToTarget");
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    //int white_pixel = 250;

    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera

    // https://docs.ros.org/en/noetic/api/sensor_msgs/html/msg/Image.html
  
    float center = 0;
    int cnt = 0;
    
    float x = 0.0;
    float z = 0.0;
    bool white_pixel;

    for (int i = 0; i < img.height ; i++) {
        for (int j = 0; j < img.width*3; j += 3) {
            white_pixel = (img.data[i * img.width*3 + j] == 250);
            white_pixel = (img.data[i * img.width*3 + j + 1] == 250) && white_pixel;
            white_pixel = (img.data[i * img.width*3 + j + 2] == 250) && white_pixel;
            if (white_pixel) {
                center += j/3.0 - img.width / 2.0;
                cnt++;
            }
        }
    }
    
    if (cnt == 0) {
        x = 0.0;
        z = 0.0;
    }
    else {
        x = 0.2;
        z = -5.0*tanh((center/cnt)/(img.width/2.0));
    }

    drive_robot(x, z);
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}