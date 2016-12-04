#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;
int main()
{
	Mat var1(200,400, CV_8UC3 ,Scalar(0,0,0));  /*CV_8UC1 is for grayscale */
	for(int j=0;j<300;j++)
	{
		for(int i=0;i<var1.rows;i++)
		{
			var1.at<Vec3b>(i,j)[0]=0;   /* <uchar> for grayscale */
			var1.at<Vec3b>(i,j)[1]=0;
			var1.at<Vec3b>(i,j)[2]=0;
		}
	}
	for(int j=300;j<var1.cols;j++)
	{
		for(int i=0;i<var1.rows;i++)
		{
			var1.at<Vec3b>(i,j)[0]=255;
			var1.at<Vec3b>(i,j)[1]=255;
			var1.at<Vec3b>(i,j)[2]=255;
		}
	}
	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1",var1);
	waitKey(0);
	return 0;
}
