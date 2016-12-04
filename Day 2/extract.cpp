#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

#define redlow 20
#define redhigh 200
#define greenlow 20
#define greenhigh 200
#define bluelow 20
#define bluehigh 200

int main()
{
	int i,j,a,b,c,k,p;
	
	
	Mat var2 = imread("2016-12-02-233631.jpg",1);
	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1",var2);
	
	
	
	
	Mat var1(var2.rows,var2.cols,CV_8UC3,Scalar(0,0,0));
	
	int red = 10,blue = 10,green = 10,thresh_red = 10,thresh_green =10,thresh_blue = 10;
	namedWindow("window4",WINDOW_AUTOSIZE);
	createTrackbar("red","window4",&red,255);
	createTrackbar("blue","window4",&blue,255);
	createTrackbar("green","window4",&green,255);
	createTrackbar("red thresh","window4",&thresh_red,255);
	createTrackbar("blue thresh","window4",&thresh_blue,255);
	createTrackbar("green thresh","window4",&thresh_green,255);
	
	while(1)
	{
	for( i = 0; i < var1.cols; i++)
	{
		
		for(j = 0; j < var1.rows ; j++)
		{
		
			a = var2.at <Vec3b>(j,i)[0];
			b = var2.at <Vec3b>(j,i)[1];
			c = var2.at <Vec3b>(j,i)[2];
			
			if(a > blue - thresh_blue && a < blue + thresh_blue && b > green - thresh_green && b < green + thresh_green && c > red - thresh_red && c < red + thresh_red)
			{
				var1.at <Vec3b>(j,i)[0] = a;
				var1.at <Vec3b>(j,i)[1] = b;
				var1.at <Vec3b>(j,i)[2] = c;
			}
			
			else
			{
				var1.at <Vec3b>(j,i)[0] = 0;
				var1.at <Vec3b>(j,i)[1] = 0;
				var1.at <Vec3b>(j,i)[2] = 0;
			}
			
		}
	}
	
	namedWindow("window2",WINDOW_AUTOSIZE);
	imshow("window2",var1);
	//int a = waitKey(1);
	waitKey(1);
	/*if(a == 'q')
	{
		break;
	}*/
	
	}
	
	
	return 0;
}
	
