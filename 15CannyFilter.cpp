#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>
using namespace std;
using namespace cv;
int main() 
{
Mat var1=imread("pic.jpg",2);
Mat var2(var1.rows , var1.cols ,CV_8UC1, Scalar(0));
Mat var3(var1.rows , var1.cols ,CV_8UC1, Scalar(0));
Mat var4(var1.rows , var1.cols ,CV_8UC1, Scalar(0));
int kernel[3][3] = {{1,2,1},{2,4,2},{1,2,1}};
int t = 0;
for(int i =0;i<var1.rows;i++)
	{ 
		for(int j =0;j<var1.cols;j++) 
		{
			int rgb = 0;
			int count = 0;
			for(int x=-1;x<2;x++)
			{
				for(int y=-1;y<2;y++)
				{
					if((i+x)>=0 && (i+x)<=var1.rows && (j+y)>=0 && (j+y)<= var1.cols)
					{
						count = count + kernel[x+1][y+1];
						rgb = rgb + var1.at<uchar>(i+x,j+y)*kernel[x+1][y+1];
					}
				}
			}
		var2.at<uchar>(i,j) = rgb/count;
		}
	}
int kernel1[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
int kernel2[3][3] = {{1,2,1},{0,0,0},{-1,-2,-1}};
for(int i =0;i<var1.rows;i++)
	{ 
		for(int j =0;j<var1.cols;j++) 
		{
			int rgb1 = 0;
			int rgb2 = 0;
			for(int x=-1;x<2;x++)
			{
				for(int y=-1;y<2;y++)
				{
					if((i+x)>=0 && (i+x)<=var1.rows && (j+y)>=0 && (j+y)<= var1.cols)
					{
						rgb1 = rgb1 + var2.at<uchar>(i+x,j+y)*kernel1[x+1][y+1];
						rgb2 = rgb2 + var2.at<uchar>(i+x,j+y)*kernel2[x+1][y+1];
					}
				}
			}
		var4.at<uchar>(i,j) = sqrt(rgb1*rgb1 + rgb2*rgb2);                          /* assert(rgb1!=0); */
			if(rgb1 == 0)
			{
				if(rgb2<0)
					t = -90;
				if(rgb2>=0)
					t = 90;
			}
			else
			{
				float tt = atan(rgb2/rgb1);
				t = tt*180/3.14 ;
			}  
			if(t/45 == 0 && t%45 <= 22)
				t = 0;
			if(t/45 == 0 && t%45 > 22)
				t = 45;
			if(t/45 == 1 && t%45 <= 22)
				t = 45;
			if(t/45 == 1 && t%45 > 22)
				t = 90;
			if(t/45 == 2 && t%45 <= 22)
				t= 90;
			if(t/45 == 2 && t%45 > 22)
				t = 135;
			if(t/45 == 3 && t%45 <= 22)
				t = 135;
			if(t/45 == 3 && t%45 > 22)
				t =0;
			if(t==0)
			{
				if((i-1)>=0 && (i+1)<=var1.rows && (j-1)>=0 && (j+1)<= var1.cols)
				{
					if(sqrt(rgb1*rgb1 + rgb2*rgb2) >= var2.at<uchar>(i,j+1) && sqrt(rgb1*rgb1 + rgb2*rgb2) >= var2.at<uchar>(i,j-1))
					{
						var3.at<uchar>(i,j) = 255;
					}
					else
						var3.at<uchar>(i,j) = 0;
				}
				if((j-1)<0)
				{
					if(sqrt(rgb1*rgb1 + rgb2*rgb2) >= var2.at<uchar>(i,j+1))
						var3.at<uchar>(i,j) = 255;
					else
						var3.at<uchar>(i,j) = 0;
				}
				if((j+1)>var1.cols)
				{
					if(sqrt(rgb1*rgb1 + rgb2*rgb2) >= var2.at<uchar>(i,j-1))
						var3.at<uchar>(i,j) = 255;
					else
						var3.at<uchar>(i,j) = 0;
				}		
			}
			if(t==45)
			{
				if((i-1)>=0 && (i+1)<=var1.rows && (j-1)>=0 && (j+1)<= var1.cols)
				{
					if(sqrt(rgb1*rgb1 + rgb2*rgb2) >= var2.at<uchar>(i-1,j+1) && sqrt(rgb1*rgb1 + rgb2*rgb2) >= var2.at<uchar>(i+1,j-1))
					{
						var3.at<uchar>(i,j) = 255;
					}
					else
						var3.at<uchar>(i,j) = 0;
				}
				if((j+1)>var1.cols && (i-1)<0)
				{
					if(sqrt(rgb1*rgb1 + rgb2*rgb2) >= var2.at<uchar>(i+1,j-1))
						var3.at<uchar>(i,j) = 255;
					else
						var3.at<uchar>(i,j) = 0;
				}
				if((j-1)<0 && (i+1)>var1.rows)
				{
					if(sqrt(rgb1*rgb1 + rgb2*rgb2) >= var2.at<uchar>(i-1,j+1))
						var3.at<uchar>(i,j) = 255;
					else
						var3.at<uchar>(i,j) = 0;
				}
			}
			if(t==90)
			{
				if((i-1)>=0 && (i+1)<=var1.rows && (j-1)>=0 && (j+1)<= var1.cols)
				{
					if(sqrt(rgb1*rgb1 + rgb2*rgb2) >= var2.at<uchar>(i-1,j) && sqrt(rgb1*rgb1 + rgb2*rgb2) >= var2.at<uchar>(i+1,j))
					{
						var3.at<uchar>(i,j) = 255;
					}
					else
						var3.at<uchar>(i,j) = 0;
				}
				if((i-1)<0)
				{
					if(sqrt(rgb1*rgb1 + rgb2*rgb2) >= var2.at<uchar>(i+1,j))
						var3.at<uchar>(i,j) = 255;
					else
						var3.at<uchar>(i,j) = 0;
				}
				if((i+1)>var1.rows)
				{
					if(sqrt(rgb1*rgb1 + rgb2*rgb2) >= var2.at<uchar>(i-1,j))
						var3.at<uchar>(i,j) = 255;
					else
						var3.at<uchar>(i,j) = 0;
				}
			}
			if(t==135)
			{
				if((i-1)>=0 && (i+1)<=var1.rows && (j-1)>=0 && (j+1)<= var1.cols)
				{
					if(sqrt(rgb1*rgb1 + rgb2*rgb2) >= var2.at<uchar>(i-1,j-1) && sqrt(rgb1*rgb1 + rgb2*rgb2) >= var2.at<uchar>(i+1,j+1))
					{
						var3.at<uchar>(i,j) = 255;
					}
					else
						var3.at<uchar>(i,j) = 0;
				}
				if((j-1)<0 && (i-1)<0)
				{
					if(sqrt(rgb1*rgb1 + rgb2*rgb2) >= var2.at<uchar>(i+1,j+1))
						var3.at<uchar>(i,j) = 255;
					else
						var3.at<uchar>(i,j) = 0;
				}
				if((i+1)>var1.rows && (j+1)>var1.cols)
				{
					if(sqrt(rgb1*rgb1 + rgb2*rgb2) >= var2.at<uchar>(i-1,j-1))
						var3.at<uchar>(i,j) = 255;
					else
						var3.at<uchar>(i,j) = 0;
				}
			}
		}
	}
namedWindow("window1",1);
namedWindow("window2",1);
namedWindow("window3",1);
namedWindow("window4",1);
imshow("window1",var1);
imshow("window2",var2);
imshow("window3",var4);
imshow("window4",var3);
waitKey(0);
return 0;
}
