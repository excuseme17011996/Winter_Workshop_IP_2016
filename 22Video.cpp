#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture Video(0); 

    if(Video.isOpened()==0)  
      return -1;

    while(1)
    {
        Mat frame;
	Mat Cframe;
        Video >> frame;

        cvtColor(frame, Cframe, CV_BGR2GRAY);
        GaussianBlur(Cframe, Cframe, Size(7,7), 1.5, 1.5);
        Canny(Cframe, Cframe, 0, 30, 3);

        imshow("My Video", Cframe);
	
     	if( waitKey(1)%256=='c' ) 
	  {
	    //destroyWindow(&"My Video");
	     namedWindow("captured",WINDOW_NORMAL);
	     //   imwrite("new.jpg",Cframe);

	     //Mat stop=imread("new.jpg");
	     imshow("captured",Cframe);
	     waitKey(0);
             break;
	  }

    }

    return 0;

}
