#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include <bits/stdc++.h>
using namespace std;
using namespace cv;

struct point{
  int x;
  int y;
};

Mat var1;

int count=0;
stack<point> S;
point a,p,q;

void CallBackFunc(int event, int y, int x, int flags, void* userdata)
{
    int visited[var1.cols][var1.rows];
     if  ( event == EVENT_LBUTTONDOWN )
     {
       for(int i=0;i<var1.rows;i++){           //initialize visited to 0
         for(int j=0;j<var1.cols;j++){
           visited[i][j]=0;
         }
       }
       int i,j;
       i=x;
       j=y;
       int color[3];
       color[0]=var1.at<Vec3b>(i,j)[0];
       color[1]=var1.at<Vec3b>(i,j)[1];
       color[2]=var1.at<Vec3b>(i,j)[2];

      p.x=i;
      p.y=j;
      S.push(p);
      visited[i][j]=1;

       while(!S.empty()){
         a=S.top();
         S.pop();
         visited[a.x][a.y]=1;
         for(int l=a.x-1;l<=a.x+1;l++){
           for(int m=a.y-1;m<=a.y+1;m++){
             if(var1.at<Vec3b>(l,m)[0]==color[0] && var1.at<Vec3b>(l,m)[1]==color[1] && var1.at<Vec3b>(l,m)[2]==color[2] && !visited[l][m]){
              var1.at<Vec3b>(l,m)[0]=0;
              var1.at<Vec3b>(l,m)[1]=0;
              var1.at<Vec3b>(l,m)[2]=255;
              q.x=l;
              q.y=m;
              S.push(q);
             }
            }
          }
       }
     imshow("windows1",var1);
     cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
}

int main()
{
   var1=imread("shapes.jpg",1);
   namedWindow("windows1",WINDOW_AUTOSIZE);
   setMouseCallback("windows1", CallBackFunc, NULL);
   imshow("windows1",var1);
//   imshow("windows2",var3);
   waitKey(0);
   return 0;
}