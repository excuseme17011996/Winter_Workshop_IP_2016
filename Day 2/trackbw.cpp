#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

#define threshold 100

int main()
{
	int i,j,a,b,c,k,p;
	
	
	Mat var2 = imread("images.jpeg",1);
	Mat var1(var2.rows,var2.cols,CV_8UC1,Scalar(0));
	Mat var3(var2.rows,var2.cols,CV_8UC1,Scalar(0));
	
	cvtColor(var2,var1,CV_RGB2GRAY);
	
	

	
	
	int f = 10;
	namedWindow("window4",WINDOW_AUTOSIZE);
	createTrackbar("track","window4",&f,255);
	while(1)
	{
		for( i = 0; i < var3.cols; i++)
		{
		
			for(j = 0; j < var3.rows ; j++)
			{
		
				p = var1.at <uchar>(j,i);
			
				if(p < f)
				{
					var3.at <uchar>(j,i) = 0;
				
				}
			
				else
				{
				
					var3.at <uchar>(j,i) = 255;
				}
			
			}
		}
	   
	    namedWindow("window3",WINDOW_AUTOSIZE);
	imshow("window3",var3);
	
	waitKey(0);
	}
	
	

	return 0;
			// at is a member function of mat . Vec3b is data typelike array of 3 dimension
}		
