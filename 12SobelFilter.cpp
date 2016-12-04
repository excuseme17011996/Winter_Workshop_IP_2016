#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>
using namespace std;
using namespace cv;
int main() 
{
Mat var1=imread("rainbow.jpeg",1);
Mat var2(var1.rows , var1.cols ,CV_8UC3, Scalar(0,0,0));
int kernel1[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
int kernel2[3][3] = {{1,2,1},{0,0,0},{-1,-2,-1}};
for(int i =0;i<var1.rows;i++)
	{ 
		for(int j =0;j<var1.cols;j++) 
		{
			int b1 = 0;
			int g1 = 0;
			int r1 = 0;
			int b2 = 0;
			int g2 = 0;
			int r2 = 0;
			for(int x=-1;x<2;x++)
			{
				for(int y=-1;y<2;y++)
				{
					if((i+x)>=0 && (i+x)<=var1.rows && (j+y)>=0 && (j+y)<= var1.cols)
					{
						b1 = b1 + var1.at<Vec3b>(i+x,j+y)[0]*kernel1[x+1][y+1];
						g1 = g1 + var1.at<Vec3b>(i+x,j+y)[1]*kernel1[x+1][y+1];
						r1 = r1 + var1.at<Vec3b>(i+x,j+y)[2]*kernel1[x+1][y+1];
						b2 = b2 + var1.at<Vec3b>(i+x,j+y)[0]*kernel2[x+1][y+1];
						g2 = g2 + var1.at<Vec3b>(i+x,j+y)[1]*kernel2[x+1][y+1];
						r2 = r2 + var1.at<Vec3b>(i+x,j+y)[2]*kernel2[x+1][y+1];
					}
				}
			}
			if(sqrt(b1*b1 + b2*b2)>255)
				var2.at<Vec3b>(i,j)[0]=255;
			else
				var2.at<Vec3b>(i,j)[0] = sqrt(b1*b1 + b2*b2);
			if(sqrt(g1*g1 + g2*g2)>255)
				var2.at<Vec3b>(i,j)[1]=255;
			else
				var2.at<Vec3b>(i,j)[1] = sqrt(g1*g1 + g2*g2);
			if(sqrt(r1*r1 + r2*r2)>255)
				var2.at<Vec3b>(i,j)[2]=255;
			else
				var2.at<Vec3b>(i,j)[2] = sqrt(r1*r1 + r2*r2);
		}
	}
namedWindow("window1",1);
namedWindow("window2",1);
imshow("window1",var1);
imshow("window2",var2);
waitKey(0);
return 0;
}
