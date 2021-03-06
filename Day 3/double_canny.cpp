#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <math.h>
using namespace cv;
using namespace std;

int main()
{
	int l_y,l_x,min=230,max=255;
	float g_x,g_y,intensity,theta;
	Mat var1 = imread("test.jpg",1);

	Mat var2(var1.rows,var1.cols,CV_8UC1,Scalar(0));
	Mat var3(var1.rows,var1.cols,CV_8UC1,Scalar(0));
	Mat var4(var1.rows,var1.cols,CV_8UC1,Scalar(0));


	namedWindow("window",WINDOW_AUTOSIZE);

	imshow("window",var1);
	createTrackbar("min","window",&min,255);
	createTrackbar("max","window",&max,255);
	

	for(int i=0;i<var1.rows;i++)
	{

		for(int j=0;j<var1.cols;j++)
		{

			var2.at<uchar>(i,j)=(var1.at<Vec3b>(i,j)[0]+var1.at<Vec3b>(i,j)[1]+var1.at<Vec3b>(i,j)[2])/3;

		}

	}

	

	

		for(int i=1;i<var1.rows-1;i++)
		{
			for(int j=1;j<var1.cols-1;j++)
			{
				g_x=var2.at<uchar>(i-1,j-1)*(-1)+var2.at<uchar>(i-1,j)*(-2)+var2.at<uchar>(i-1,j+1)*(-1)+var2.at<uchar>(i+1,j-1)*(1)+var2.at<uchar>(i+1,j)*(2)+var2.at<uchar>(i+1,j+1)*(1);

				g_y=var2.at<uchar>(i-1,j-1)*(-1)+var2.at<uchar>(i,j-1)*(-2)+var2.at<uchar>(i+1,j-1)*(-1)+var2.at<uchar>(i-1,j+1)*(1)+var2.at<uchar>(i,j+1)*(2)+var2.at<uchar>(i+1,j+1)*(1);


				intensity=(int)sqrt(g_x*g_x+g_y*g_y);


				theta=atan(g_y/g_x);

				if(theta>-(3.14/8)&&theta<3.14/8&&var2.at<uchar>(i,j-1)<intensity&&var2.at<uchar>(i,j+1)<intensity)
					var3.at<uchar>(i,j)=intensity;

				if(theta>3.14/8&&theta<3*3.14/8&&var2.at<uchar>(i-1,j+1)<intensity&&var2.at<uchar>(i+1,j-1)<intensity)
					var3.at<uchar>(i,j)=intensity;

				if(theta>-(3*3.14/8)&&theta<-(3.14/8)&&var2.at<uchar>(i+1,j+1)<intensity&&var2.at<uchar>(i-1,j-1)<intensity)
					var3.at<uchar>(i,j)=intensity;

				if(theta<-(3*3.14/8)&&var2.at<uchar>(i+1,j)<intensity&&var2.at<uchar>(i-1,j)<intensity)
					var3.at<uchar>(i,j)=intensity;

				if(theta>3*3.14/8&&var2.at<uchar>(i+1,j)<intensity&&var2.at<uchar>(i-1,j)<intensity)
					var3.at<uchar>(i,j)=intensity;

			}
		}



		while(1)
		{

			

			for(int i=0;i<var1.rows;i++)
			{
				for(int j=0;j<var1.cols;j++)
				{
					if(var3.at<uchar>(i,j)>min&&var3.at<uchar>(i,j)<max)
						var4.at<uchar>(i,j)=var3.at<uchar>(i,j);
					else
					{
						var4.at<uchar>(i,j)=0;
					}
				}
			}

			imshow("window",var4);
			if(waitKey(10)=='q')
				break;

		}

	

	


	return 0;

}