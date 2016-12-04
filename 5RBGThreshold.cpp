#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;
int main() {
Mat var1=imread("rainbow.jpeg",1);
Mat var2(var1.rows,var1.cols, CV_8UC3 ,Scalar(255,255,255));
for(int j=0;j<var1.cols;j++)
	{
		for(int i=0;i<var1.rows;i++)
		{
		if(var1.at<Vec3b>(i,j)[0]>150 && var1.at<Vec3b>(i,j)[1]<60 && var1.at<Vec3b>(i,j)[2]<60)
		{
			var2.at<Vec3b>(i,j)[0] = 255;
			var2.at<Vec3b>(i,j)[1] = 0;
			var2.at<Vec3b>(i,j)[2] = 0;
		}
		if(var1.at<Vec3b>(i,j)[1]>150 && var1.at<Vec3b>(i,j)[0]<60 && var1.at<Vec3b>(i,j)[2]<60)
		{
			var2.at<Vec3b>(i,j)[0] = 0;
			var2.at<Vec3b>(i,j)[1] = 255;
			var2.at<Vec3b>(i,j)[2] = 0;
		}
		if(var1.at<Vec3b>(i,j)[2]>150 && var1.at<Vec3b>(i,j)[1]<60 && var1.at<Vec3b>(i,j)[0]<60)
		{	
			var2.at<Vec3b>(i,j)[0] = 0;
			var2.at<Vec3b>(i,j)[1] = 0;
			var2.at<Vec3b>(i,j)[2] = 255;
		}

		}
	}
namedWindow("window1",WINDOW_AUTOSIZE);
namedWindow("window2",WINDOW_AUTOSIZE);
imshow("window1",var1);
imshow("window2",var2);
waitKey(0);
return 0 ;
}

