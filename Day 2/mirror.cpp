#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main()
{
	Mat var2 = imread("images.jpeg",1);
	Mat var1(var2.rows,var2.cols,CV_8UC3,Scalar(0,0,0));
	int i,j,a,b,c;
	
	
	for( i = 0; i < var1.cols; i++)
	{
		
		for(j = 0; j < var1.rows ; j++)
		{
		
			a = var2.at <Vec3b>(j,i)[0];
			b = var2.at <Vec3b>(j,i)[1];
			c = var2.at <Vec3b>(j,i)[2];
			
			
			
			var1.at <Vec3b>(j,var1.cols - i)[0] = a;
			var1.at <Vec3b>(j,var1.cols - i)[1] = b;
			var1.at <Vec3b>(j,var1.cols - i)[2] = c;
			
			
		}
	}
	
	namedWindow("window2",WINDOW_AUTOSIZE);
	imshow("window2",var2);
	
	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1",var1);
	
	waitKey(0);
	return 0;
}
