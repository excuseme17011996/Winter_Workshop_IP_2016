#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;
int main() {
Mat var1=imread("rainbow.jpeg",1);
Mat var2(var1.rows,var1.cols, CV_8UC3 ,Scalar(0,0,0));
int R = 200;
int G = 200;
int B = 200;
int r = 2;
int g = 2;
int b = 2;
namedWindow("window1",1);
createTrackbar("TR","window1",&R,255);
createTrackbar("TG","window1",&G,255);
createTrackbar("TB","window1",&B,255);
createTrackbar("Tr","window1",&r,255);
createTrackbar("Tg","window1",&g,255);
createTrackbar("Tb","window1",&b,255);
while(1)
{
	for (int i =0;i<var1.rows;i++)
	{ 
		for(int j =0;j<var1.cols;j++) 
		{
			if (var1.at<Vec3b>(i,j)[0] >= (B-b) && var1.at<Vec3b>(i,j)[0] <= (B+b) ) 
				var2.at<Vec3b>(i,j)[0] = var1.at<Vec3b>(i,j)[0];
			else
				var2.at<Vec3b>(i,j)[0] = 0;
			if (var1.at<Vec3b>(i,j)[1] >= (G-g) && var1.at<Vec3b>(i,j)[1] <= (G+g) ) 
				var2.at<Vec3b>(i,j)[1] = var1.at<Vec3b>(i,j)[1];
			else
				var2.at<Vec3b>(i,j)[1] = 0;
			if (var1.at<Vec3b>(i,j)[2] >= (R-r) && var1.at<Vec3b>(i,j)[2] <= (R+r) ) 
				var2.at<Vec3b>(i,j)[2] = var1.at<Vec3b>(i,j)[2];
			else
				var2.at<Vec3b>(i,j)[2] = 0;
		}
	}
	
imshow("window1",var2);
waitKey(1);
}
return 0 ;
}

