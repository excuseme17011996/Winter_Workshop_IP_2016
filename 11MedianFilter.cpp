#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <algorithm>
using namespace std;
using namespace cv;
int main() 
{
Mat var1=imread("rainbow.jpeg",1);
Mat var2(var1.rows , var1.cols ,CV_8UC3, Scalar(0,0,0));
int kernel[3][3] = {{1,1,1},{1,1,1},{1,1,1}};
for(int i =0;i<var1.rows;i++)
	{ 
		for(int j =0;j<var1.cols;j++) 
		{
			int r[9] = {0};
			int g[9] = {0};
			int b[9] = {0};
			int count = 0;
			int q =0;
			for(int x=-1;x<2;x++)
			{
				for(int y=-1;y<2;y++)
				{
					if((i+x)>=0 && (i+x)<=var1.rows && (j+y)>=0 && (j+y)<= var1.cols)
					{
						count = count + kernel[x+1][y+1];
						b[q] = var1.at<Vec3b>(i+x,j+y)[0]*kernel[x+1][y+1];
						g[q] = var1.at<Vec3b>(i+x,j+y)[1]*kernel[x+1][y+1];
						r[q] = var1.at<Vec3b>(i+x,j+y)[2]*kernel[x+1][y+1];
						q = q + 1;
					}
				}
			}
		sort(b,b+count);
		sort(g,g+count);
		sort(r,r+count);
		var2.at<Vec3b>(i,j)[0] = b[q/2];
		var2.at<Vec3b>(i,j)[1] = g[q/2];
		var2.at<Vec3b>(i,j)[2] = r[q/2];
		}
	}
namedWindow("window1",1);
namedWindow("window2",1);
imshow("window1",var1);
imshow("window2",var2);
waitKey(0);
return 0;
}
