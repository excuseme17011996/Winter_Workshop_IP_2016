#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>
using namespace std;
using namespace cv;
int main() 
{
Mat var1=imread("rainbow.jpeg",2);
Mat var2(var1.rows , var1.cols ,CV_8UC1, Scalar(0));
int kernel1[3][3] = {{0,0,0},{-1,0,1},{0,0,0}};
int kernel2[3][3] = {{0,1,0},{0,0,0},{0,-1,0}};
namedWindow("window1",1);
namedWindow("window2",1);
imshow("window1",var1);
int rgb = 255;
createTrackbar("TR","window2",&rgb,255);
while(1)
{
for(int i =0;i<var1.rows;i++)
	{ 
		for(int j =0;j<var1.cols;j++) 
		{
			int Lx = 0;
			int Ly = 0;
			for(int x=-1;x<2;x++)
			{
				for(int y=-1;y<2;y++)
				{
					if((i+x)>=0 && (i+x)<=var1.rows && (j+y)>=0 && (j+y)<= var1.cols)
					{
						Lx = Lx + var1.at<uchar>(i+x,j+y)*kernel1[x+1][y+1];
						Ly = Ly + var1.at<uchar>(i+x,j+y)*kernel2[x+1][y+1];
					}
				}
			}
			Lx = Lx/2;
			Ly = Ly/2;
			if(sqrt(Lx*Lx + Ly*Ly)>=rgb)
				var2.at<uchar>(i,j)=255;
			else
				var2.at<uchar>(i,j) = 0;
		}
	}
imshow("window2",var2);
waitKey(1);
}
return 0;
}
