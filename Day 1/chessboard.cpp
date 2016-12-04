#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

int main()
{
	int i,j,r,c;
	//mat var1(80,150,CV_8UC3,scalar(0,0,0));
	Mat var1(800,800,CV_8UC1,Scalar(0));
	
	//constructor( no.of rows, no. of cols,  ,initialize BGR
	
	for( i = 100; i < var1.cols ; i = i + 200)
	{
		for(j = 0; j < (var1.rows) ; j = j+200)
		{
			for(r = i; r < i + 100; r++)
			{
				for(c = j; c < j + 100; c++)
				{//var1.at <Vec3b>(i,j)[0] = 255;
					var1.at <uchar>(c,r) = 255;
				}
			}
		}
		
	}
	
	for( i = 0; i < var1.cols ; i = i + 200)
	{
		for(j = 100; j < (var1.rows) ; j = j+200)
		{
			for(r = i; r < i + 100; r++)
			{
				for(c = j; c < j + 100; c++)
				{//var1.at <Vec3b>(i,j)[0] = 255;
					var1.at <uchar>(c,r) = 255;
				}
			}
		}
		
	}
	
	
	
	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1",var1);
	waitKey();
	return 0;
			// at is a member function of mat . Vec3b is data typelike array of 3 dimension
}		

