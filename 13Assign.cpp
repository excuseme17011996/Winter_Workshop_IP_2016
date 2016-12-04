#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;
int main()
{
	Mat var1(600,600, CV_8UC3 ,Scalar(0,0,0));
	for(int j=0;j<var1.cols;j++)
	{
		for(int i=0;i<var1.rows;i++)
		{
			if((2*i<=var1.rows && 2*j<var1.cols && j<=i)||(2*i>=var1.rows && 2*j<=var1.cols && j<=var1.rows-i))
			{
				var1.at<Vec3b>(i,j)[0]=255;
				var1.at<Vec3b>(i,j)[1]=255;
				var1.at<Vec3b>(i,j)[2]=255;
			}
			if((2*i<=var1.rows && 2*j<=var1.cols && j>=i)||(2*i<=var1.rows && 2*j>=var1.cols && j<=var1.rows-i))
			{
				var1.at<Vec3b>(i,j)[0]=0;
				var1.at<Vec3b>(i,j)[1]=0;
				var1.at<Vec3b>(i,j)[2]=255;
			}
			if((2*i<=var1.rows && 2*j>=var1.cols && j>=var1.rows-i)||(2*i>=var1.rows && 2*j>=var1.cols && j>=i))
			{
				var1.at<Vec3b>(i,j)[0]=255;
				var1.at<Vec3b>(i,j)[1]=0;
				var1.at<Vec3b>(i,j)[2]=0;
			}
			if((2*i>=var1.rows && 2*j<=var1.cols && j>=var1.rows-i)||(2*i>=var1.rows && 2*j>=var1.cols && j<=i))
			{
				var1.at<Vec3b>(i,j)[0]=0;
				var1.at<Vec3b>(i,j)[1]=255;
				var1.at<Vec3b>(i,j)[2]=0;
			}
		}
	}
	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1",var1);
	waitKey(0);
	return 0;
} /*WRBG clockwise */
