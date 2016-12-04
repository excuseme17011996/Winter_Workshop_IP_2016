#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main()
{
	Mat var1 = imread("images.jpeg",1);
	
	 //creates an object of name mat //mat is a matrix that stores RGB or HSL of a pixel
	//1 indicates colour image and 0 indicates black and white image
	
	namedWindow("window1",WINDOW_AUTOSIZE);
	
	Mat var2 = imread("images.jpeg",0);
	
	
	
	//cvtColor(var1,var2,CV_RGB2GRAY);
	//cvtColor(var1,var3,CV_BGR2HSV);
	//cvtColor(var3,var4,CV_HSV2BGR);
	
	
	
	namedWindow("window2",WINDOW_AUTOSIZE);
	//namedWindow("window3",WINDOW_AUTOSIZE);
	//namedWindow("window4",WINDOW_AUTOSIZE);
	
	//imshow("window4",var4);
	
	//imshow("window3",var3);
	
	imshow("window1",var1);
	imshow("window2",var2);
	
	waitKey(0); // it waits untill we press some button
	
	return 0;
}
