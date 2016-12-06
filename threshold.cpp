#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
  Mat image=imread("love.jpg",1);

  namedWindow("original",WINDOW_NORMAL);
  imshow("original",image);
  waitKey(0);

  Mat hsv;
  cvtColor(image,hsv,CV_BGR2HSV);

  namedWindow("converted",WINDOW_NORMAL);
  imshow("converted",hsv);
  waitKey(0);

   Mat image2(image.rows,image.cols,CV_8UC3,Scalar(0,0,0));
   cvtColor(image2,image2,CV_BGR2HSV);

   int h1,s1,v1;
   int h2,s2,v2;

   namedWindow("HSV",WINDOW_NORMAL);
   createTrackbar("hue-low","HSV",&h1,180);
   createTrackbar("hue-high","HSV",&h2,180);
   createTrackbar("saturation-low","HSV",&s1,255);
   createTrackbar("saturation-high","HSV",&s2,255);
   createTrackbar("value-low","HSV",&v1,255);
   createTrackbar("value-high","HSV",&v2,255);

  int i,j;
  int h,s,v;

  namedWindow("WW",WINDOW_NORMAL);

  while(1)
    {
      for(i=0;i<hsv.rows;i++)
	{
	  for(j=0;j<hsv.cols;j++)
	    {
	      h = hsv.at<Vec3b>(i,j)[0]; 
	      s = hsv.at<Vec3b>(i,j)[1]; 
	      v = hsv.at<Vec3b>(i,j)[2];
	      if(h<h1 || h>h2)
		{
		  image2.at<Vec3b>(i,j)[0]=0;
		}
	      else
		{
		  image2.at<Vec3b>(i,j)[0]= hsv.at<Vec3b>(i,j)[0];
		}
	      if(s<s1 || s>s2)
		{
		  image2.at<Vec3b>(i,j)[1]=0;
		}
	      else
		{
                    image2.at<Vec3b>(i,j)[1]= hsv.at<Vec3b>(i,j)[1];
		}
	      if(v<v1 || v>v2)
		{
		  image2.at<Vec3b>(i,j)[2]=0;
		}
	      else
		{
                    image2.at<Vec3b>(i,j)[2]= hsv.at<Vec3b>(i,j)[2];
		}
	    }
	}
      //  cvtColor(image2,image2,CV_HSV2BGR);
      imshow("WW",image2);
      waitKey(10);
    }
  return 0;
}
      
