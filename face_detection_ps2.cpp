#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<deque>
#include "opencv2/objdetect/objdetect.hpp"
#include <fstream>
#include<string>
#include<string.h>
using namespace std;
using namespace cv;
String face_cascade_name="haarcascade_frontalface_alt.xml";
CascadeClassifier face_cascade;
typedef struct l
{
  int x;
  int y;
}my_pair;
int main(int count,char *arg[])
{
  VideoCapture video("pvideo.mp4");
  string text="count: ";
  bool b=true;
  int max;
  Mat inp;
  int cnt=0;
  Point p;
  HOGDescriptor hog;
  my_pair temp;
  ofstream myfile;
  temp.x=10000;
  namedWindow("winow1",WINDOW_NORMAL);
  if(!(face_cascade.load(face_cascade_name)))
    {
      cout << "face cascade was not able to load."; 
    }
  while(video.isOpened())
    {
      for(int i=0;i<15;++i)
	{
	  video >> inp;
	}
      vector<Rect> faces;
      Mat grey;
      cvtColor(inp,grey,CV_BGR2GRAY);
      face_cascade.detectMultiScale(grey,faces,1.1,8,0|CV_HAAR_SCALE_IMAGE, Size(30, 30));
      b=true;
      for(int i=0;i<faces.size();++i)
	{
	  if(faces[i].x > temp.x)
	    {
	      temp.x=faces[i].x;
	      b=false;
	    }
	  else
	    {
	      
	      temp.x=faces[i].x ;
	      ++cnt;
	      p.x=150;
	      p.y=200;
	      text[6]=char(cnt+'0');
		
	    }
	  Point p1(faces[i].x,faces[i].y);
	  Point p2(faces[i].x+faces[i].height,faces[i].y+faces[i].width);
	  rectangle(inp,p1,p2,Scalar(0,0,255),4);
	}
      putText(inp,text,p,FONT_HERSHEY_SIMPLEX,4,Scalar(0,0,255),4);
      imshow("winow1",inp);
      waitKey(5);
    }
  waitKey(0);
  return 0;
}
