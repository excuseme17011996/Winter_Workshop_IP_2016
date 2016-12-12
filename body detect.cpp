#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include <bits/stdc++.h>
using namespace std;
using namespace cv;

Mat source,result;
CascadeClassifier fullbody;

void detect();

int main(){
  VideoCapture a(0);

  fullbody.load("haarcascade_fullbody.xml");

  while(a.isOpened()){
    a>>source;
    detect();
  }

}

void detect(){
  Vector<Rect> body;
  Mat gray;
  cvtColor(source,gray,CV_BGR2GRAY);
  equalizeHist(gray,gray);
  fullbody.detectMultiScale(gray,body, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );    //why???
  for( size_t i = 0; i < body.size(); i++ )
  {
    Point p1( body[i].x, body[i].y);
    Point p2( body[i].x + body[i].width, body[i].y + body[i].height);
    rectangle(source,p1,p2,Scalar(0,0,255),1,8,0);
  }
  imshow("Detected",source);
}