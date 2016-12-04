#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;
int main()
{
	Mat var1(640,640, CV_8UC3 ,Scalar(0,0,0));
	for(int j=0;j<var1.cols;j++)
	{
		for(int i=0;i<var1.rows;i++)
		{
			if((i/80 + j/80)%2 == 0)
			{
				var1.at<Vec3b>(i,j)[0]=0;
				var1.at<Vec3b>(i,j)[1]=0;
				var1.at<Vec3b>(i,j)[2]=0;
			}
			else
			{
				var1.at<Vec3b>(i,j)[0]=255;
				var1.at<Vec3b>(i,j)[1]=255;
				var1.at<Vec3b>(i,j)[2]=255;
			}
		}
	}
	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1",var1);
	waitKey(0);
	return 0;
}
