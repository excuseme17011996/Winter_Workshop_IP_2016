#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;
int main()
{
	Mat var1=imread("rainbow.jpeg",1);
	Mat var2(2*var1.rows,2*var1.cols,CV_8UC3,Scalar(0,0,0));
	for(int j=0;j<var1.cols;j++)
	{
		for(int i=0;i<var1.rows;i++)
		{
			for(int k = 2*i; k<=2*i+1 ; k++)
			{
				for(int l = 2*j; l<=2*j+1 ; l++)
				{
					var2.at<Vec3b>(k,l)[0]=var1.at<Vec3b>(i,j)[0];
					var2.at<Vec3b>(k,l)[1]=var1.at<Vec3b>(i,j)[1];
					var2.at<Vec3b>(k,l)[2]=var1.at<Vec3b>(i,j)[2];
				}
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
