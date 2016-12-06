#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;

int main()
{
   Mat var0=imread("erosion.jpg",0);
   Mat var1(var0.rows,var0.cols,CV_8UC1,Scalar(0));
   threshold(var0,var1, 128.0, 255.0, THRESH_BINARY);
   Mat var2(var1.rows,var1.cols,CV_8UC1,Scalar(0));
   Mat var3(var1.rows,var1.cols,CV_8UC1,Scalar(0));
   namedWindow("windows1",WINDOW_AUTOSIZE);
   imshow("window1",var1);
   for(int i=0;i<var1.rows;i++){
   	for(int j=0;j<var1.cols;j++){
      int flag=0;
      for(int a=0;a<3;a++){
        for(int b=0;b<3;b++){
          int p=var1.at<uchar>(i-1+a,j-1+b);
          if(a!=1 && b!=1 && p==0)
            flag=1;
        }
      }
      if(flag==1)
        var2.at<uchar>(i,j)=0;
      else
        var2.at<uchar>(i,j)=255;
   	}
   }
   for(int i=0;i<var1.rows;i++){
     for(int j=0;j<var1.cols;j++){
      int flag=0;
      for(int a=0;a<3;a++){
        for(int b=0;b<3;b++){
          int p=var2.at<uchar>(i-1+a,j-1+b);
          if(a!=1 && b!=1 && p==255)
            flag=1;
        }
      }
      if(flag==1)
        var3.at<uchar>(i,j)=255;
      else
        var3.at<uchar>(i,j)=0;
     }
   }
   namedWindow("windows2",WINDOW_AUTOSIZE);
   imshow("window2",var2);
   namedWindow("windows4",WINDOW_AUTOSIZE);
   imshow("window3",var3);
   waitKey(0);
   return 0;
}