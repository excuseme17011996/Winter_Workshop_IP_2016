#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

#define threshold 100

int main()
{
	int i,j,a,b,c,k,p;
	
	
	Mat var2 = imread("images.jpeg",1);
	Mat var1(var2.rows,var2.cols,CV_8UC3,Scalar(0,0,0));
	
	
	for( i = 0; i < var1.cols; i++)
	{
		
		for(j = 0; j < var1.rows ; j++)
		{
		
			a = var2.at <Vec3b>(j,i)[0];
			b = var2.at <Vec3b>(j,i)[1];
			c = var2.at <Vec3b>(j,i)[2];
			
			k = (a+b+c)/3;
			
			var1.at <Vec3b>(j,i)[0] = k;
			var1.at <Vec3b>(j,i)[1] = k;
			var1.at <Vec3b>(j,i)[2] = k;
			
			
		}
	}
	
	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1",var2);
	
	
	for( i = 0; i < var1.cols; i++)
	{
		
		for(j = 0; j < var1.rows ; j++)
		{
		
			a = var1.at <Vec3b>(j,i)[0];
			b = var1.at <Vec3b>(j,i)[1];
			c = var1.at <Vec3b>(j,i)[2];
			
			k = (a+b+c)/3;
			
			var1.at <Vec3b>(j,i)[0] = k;
			var1.at <Vec3b>(j,i)[1] = k;
			var1.at <Vec3b>(j,i)[2] = k;
			
			
		}
	}
	
	
	namedWindow("window2",WINDOW_AUTOSIZE);
	imshow("window2",var1);
	
	namedWindow("window4",WINDOW_AUTOSIZE);
	
	Mat var3 = var1;
	
	int f = 10;
	createTrackbar("track","window4",&f,255);
	while(1)
	{for( i = 0; i < var3.cols; i++)
	{
		
		for(j = 0; j < var3.rows ; j++)
		{
		
			p = var3.at <Vec3b>(j,i)[0];
			
			if(p < f)
			{
				var3.at <Vec3b>(j,i)[0] = 0;
				var3.at <Vec3b>(j,i)[1] = 0;
				var3.at <Vec3b>(j,i)[2] = 0;
			}
			
			else
			{
				var3.at <Vec3b>(j,i)[0] = 255;
				var3.at <Vec3b>(j,i)[1] = 255;
				var3.at <Vec3b>(j,i)[2] = 255;
			}
			
			
			
		}
	}}
	/*namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1",var2);
	namedWindow("window2",WINDOW_AUTOSIZE);
	imshow("window2",var1);*/
	namedWindow("window3",WINDOW_AUTOSIZE);
	imshow("window3",var3);
	
	waitKey(0);
	return 0;
			// at is a member function of mat . Vec3b is data typelike array of 3 dimension
}		
