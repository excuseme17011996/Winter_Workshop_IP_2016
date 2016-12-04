#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;
int main()
{
	Mat var1=imread("images.jpeg",1);
	Mat var2((var1.rows*var1.cols+1)/40,255,CV_8UC3,Scalar(0,0,0));
	int Blue[255] = {0};
	int Green[255] = {0};
	int Red[255] = {0};
	for(int j=0;j<var1.cols;j++)
	{
		for(int i=0;i<var1.rows;i++)
		{
			Blue[var1.at<Vec3b>(i,j)[0]]++;
			Green[var1.at<Vec3b>(i,j)[1]]++;
			Red[var1.at<Vec3b>(i,j)[2]]++;
		}
	}
	for(int x=0;x<256;x++)
	{
	
	}
	for(int j=0;j<var2.cols;j++)
	{
		for(int i=0;i<var2.rows;i++)
		{
			if(var2.rows-i == Blue[j]/40)
			{
				var2.at<Vec3b>(i,j)[0] = 255;
			}
			if(var2.rows-i == Green[j]/40)
			{
				var2.at<Vec3b>(i,j)[1] = 255;
			}
			if(var2.rows-i == Red[j]/40)
			{
				var2.at<Vec3b>(i,j)[2] = 255;
			}
		}
	}
	namedWindow("window1",WINDOW_AUTOSIZE);
	namedWindow("window2",WINDOW_AUTOSIZE);
	imshow("window1",var1);
	imshow("window2",var2);
	waitKey(0);
	return 0;
}
