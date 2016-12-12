#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
  VideoCapture Video(0);  

  //videocapture-class
  //video - object of a class
  //(0) constructor
  //inside the braces - device id from which video is to be taken [ 0-id of laptops camera]
  // the statement reads input from our device camera and assigns it to the object

    // Video is ntg but a series of images mving faster than the perception of the eye
                // image in the video at a particular instant of time- store it in the variable 'frame' for further use

  if(Video.isOpened()==0)
    {
      return -1;
    }
  else
    {
      while(1)
	{
           Mat frame; 
	  Video >> frame;  //get an image at that instant from the camera

	  namedWindow("Your Video",WINDOW_NORMAL);
	  imshow("Your Video",frame);
	  if( waitKey(30)>=0 )
	    {
	      break;
	    }
	}
    }
  return 0;
}

