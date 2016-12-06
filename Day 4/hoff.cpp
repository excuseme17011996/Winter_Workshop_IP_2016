#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <bits/stdc++.h>

using namespace cv;

//![variables]
Mat src, src_gray;
Mat dst, detected_edges;

int edgeThresh = 1;
int lowThreshold=100;
int const max_lowThreshold = 255;
int ratio = 3;
int kernel_size = 3;
const char* window_name = "Edge Map";
int D=10,L=100,count;


static void CannyThreshold(int, void*)
{
    blur( src_gray, detected_edges, Size(3,3) );
    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
    dst = Scalar::all(0);
    src.copyTo( dst, detected_edges);
    imshow( window_name, dst );

}

void hoff(){
  int r=sqrt((dst.rows*dst.rows)+(dst.cols*dst.cols));
  int line[r][180];
  float d;
  count=0;
    for(int i=0;i<r;i++){
      for(int j=0;j<180;j++){
        line[i][j]=0;
      }
    }
    createTrackbar( "D", window_name, &D,100);
    createTrackbar( "L", window_name, &L,100000);
    for(int i=0;i<r;i++){
      for(int j=0;j<180;j++){
        for(int a=0;a<r;a++){
          for(int b=0;b<180;b++){
            line[i][j]=0;
            if(dst.at<uchar>(a,b)==255)
            {
              d=(a*cos(j*3.14/180)+b*sin(j*3.14/180)-i);
              d=(int)abs(d);
              if(d<D){
                line[i][j]++;
              }
            }
          }
        }
      }
    }
    for(int i=0;i<r;i++){
      for(int j=0;j<180;j++){
        if(line[i][j]>L)
          count++;
      }
    }
    imshow( window_name, dst );
    printf("%d",count);
}

int main( )
{
  src = imread("line.jpg", IMREAD_COLOR ); // Load an image

  if( src.empty() )
    { return -1; }
  dst.create( src.size(), src.type() );

  cvtColor( src, src_gray, COLOR_BGR2GRAY );

  namedWindow( window_name, WINDOW_AUTOSIZE );
  CannyThreshold(0, 0);
  while(1){
  hoff();
  }
  /// Wait until user exit program by pressing a key
  waitKey(0);

  return 0;
}