#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;
int main() {
Mat var1=imread("images.jpeg",1);
Mat var2(var1.rows,var1.cols, CV_8UC1 ,Scalar(0));
Mat var3(var1.rows,var1.cols, CV_8UC1 ,Scalar(0));
for(int j=0;j<var1.cols;j++)
	{
		for(int i=0;i<var1.rows;i++)
		{
			var2.at<uchar>(i,j)=(var1.at<Vec3b>(i,j)[0]+var1.at<Vec3b>(i,j)[1]+var1.at<Vec3b>(i,j)[2])/3;

		}
	}
for(int j=0;j<var1.cols;j++)
	{
		for(int i=0;i<var1.rows;i++)
		{
			if(var2.at<uchar>(i,j) < 150)
			{
				var3.at<uchar>(i,j)= 0;
			}
			else
			{
				var3.at<uchar>(i,j)= 255;
			}

		}
	}                                                           /* IMPELMENTATION - cvtColor(var1 , var2 , CV_RGB2GRAY); */
namedWindow("window1",WINDOW_AUTOSIZE);
namedWindow("window2",WINDOW_AUTOSIZE);
namedWindow("window3",WINDOW_AUTOSIZE);
imshow("window1",var1);
imshow("window2",var2);
imshow("window3",var3);
waitKey(0);
return 0 ;
}



/* cvtColor(inputMatvariable,outputMatvariable,____)
						\\\
					     CV_RGB2GRAY
					     CV_BGR2HSV
					     CV_HSV2BGR */
