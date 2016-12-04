#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

int main()
{
	int i,j;
	//mat var1(100,50,CV_8UC3,scalar(0,0,0));
	Mat var1(200,400,CV_8UC1,Scalar(0));
	 cout << "M = " << endl << " " << M << endl << endl;
	
	//constructor( no.of rows, no. of cols,  ,initialize BGR
	
	for( i = 0; i < ((var1.cols * 3)/4); i++)
	{
		
		for(j = 0; j < var1.rows ; j++)
		{
		
			//var1.at <Vec3b>(i,j)[0] = 255;
			var1.at <uchar>(j,i) = 255;
		}
	}
	
	for(i = (((var1.cols) * 3)/4); i < var1.cols; i++)
	{
		
		for(j = 0; j < var1.rows ; j++)
		{
		
			//var1.at <Vec3b>(i,j)[0] = 255;
			var1.at <uchar>(j,i) = 0;
		}
	}
	
	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1",var1);
	waitKey(0);
	return 0;
			// at is a member function of mat . Vec3b is data typelike array of 3 dimension
}		

