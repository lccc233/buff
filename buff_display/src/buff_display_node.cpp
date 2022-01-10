#include<opencv2/opencv.hpp>
#include<ros/ros.h>
#include<math.h>
int main(int argc, char** argv){
	ros::init(argc, argv, "buff_display_node");
	ros::NodeHandle n;
	ros::Rate loop_rate(60);
	int num=0;
    double tim=0;
	double digal=0;
    double predict_tim=3.1415926535/2;
	cv::namedWindow("BUFF",cv::WINDOW_AUTOSIZE);
	cv::Mat show_buff(1000,1000,CV_8UC3,cv::Scalar(0,255,0));
	while(ros::ok()){
		show_buff=cv::Mat(1000,1000,CV_8UC3,cv::Scalar(0,255,0));
		cv::Point center_point,aim_point,final_point;
		center_point.x=500;
		center_point.y=500;
		tim+=0.01;
        final_point.x=500+400*cos(digal+abs(sin(predict_tim))/60);
        final_point.y=500+400*sin(digal+abs(sin(predict_tim))/60);
        digal+=abs(sin(tim))/60;
        aim_point.x=500+400*cos(digal);
        aim_point.y=500+400*sin(digal);
		cv::circle(show_buff,center_point,10,cv::Scalar(255,0,0),-1);
		cv::circle(show_buff,aim_point,10,cv::Scalar(0,0,255),-1);
		cv::circle(show_buff,final_point,10,cv::Scalar(255,0,255),-1);
		cv::line(show_buff,center_point,aim_point,cv::Scalar(0,255,255),5);
		imshow("BUFF",show_buff);
		cv::waitKey(1);
		num++;
        if(abs(final_point.x-aim_point.x)<=10&&abs(final_point.y-aim_point.y)<10){
            predict_tim+=0.01;
        }
		ROS_INFO("%f\n",sin(digal)*3.1415926535*2);
		loop_rate.sleep();
	}
	return 0;
}
