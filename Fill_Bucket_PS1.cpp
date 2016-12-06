// use right click to select color
// use left click to fill color
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include<stack>
#include<stdio.h>
#include<iostream>
#include<stack>

using namespace cv;
using namespace std;

Mat var1 = imread("shapes.jpg",1);

struct abc
{
	int i;
	int j;
};

typedef struct abc point;

struct fsd
{
	int b;
	int g;
	int r;
};

typedef struct fsd color;

int mod(int a)
{
	if(a < 0)
		return -a;
	else
		return a;
}

color clr;

int checkcolor(Mat var2,point a,int p,int q)
{
	int b1=var2.at<Vec3b>(a.i,a.j)[0];
	int g1=var2.at<Vec3b>(a.i,a.j)[1];
	int r1=var2.at<Vec3b>(a.i,a.j)[2];
	int b2=var2.at<Vec3b>(p,q)[0];
	int g2=var2.at<Vec3b>(p,q)[1];
	int r2=var2.at<Vec3b>(p,q)[2];
	if(mod(r1-r2) < 50 && mod(b1-b2) < 50 && mod(g1-g2) < 50)
	{
		return 1;
	}
	else
		return 0;
}

void dfs(int i,int j)
{
	Mat var2=var1.clone();
	stack<point> s;
	Mat var3(var1.rows,var1.cols,CV_8UC1,Scalar(0));
	point a,b,c;
	a.i=i;
	a.j=j;
	var3.at<uchar>(i,j)=255;
	var1.at<Vec3b>(i,j)[0]=clr.b;
    var1.at<Vec3b>(i,j)[1]=clr.g;
    var1.at<Vec3b>(i,j)[2]=clr.r;
    s.push(a);
    while(!s.empty())
    {
    	b=s.top();
    	s.pop();
    	if(b.i == 0 || b.i == var1.rows-1 || b.j == 0 || b.j == var1.cols-1)
    		continue;
    	else
    	{
    		for(int p=-1;p<=1;p++)
    		{
    			for(int q=-1;q<=1;q++)
    			{
    				if(var3.at<uchar>(b.i+p,b.j+q) == 0)
    				{
    					if(checkcolor(var2,a,b.i+p,b.j+q) == 1)
    					{
    						c.i=b.i+p;
    						c.j=b.j+q;
    						var1.at<Vec3b>(c.i,c.j)[0]=clr.b;
    						var1.at<Vec3b>(c.i,c.j)[1]=clr.g;
    						var1.at<Vec3b>(c.i,c.j)[2]=clr.r;
    						var3.at<uchar>(c.i,c.j)=255;
    						s.push(c);
    					}
    				}
    			}
    		}
    	}
    }
}

void CallBackFunc(int event, int y, int x, int flags, void* userdata)
{
	if(event == EVENT_LBUTTONDOWN)
	{
		dfs(x,y);
	}
	if(event == EVENT_RBUTTONDOWN)
	{
		clr.b=var1.at<Vec3b>(x,y)[0];
		clr.g=var1.at<Vec3b>(x,y)[1];
		clr.r=var1.at<Vec3b>(x,y)[2];
	}
}

int main()
{
	namedWindow("windows1",WINDOW_AUTOSIZE);
	clr.b=0;
    clr.g=0;
    clr.r=255;
    int i,j;
	while(1){
	for(i=0;i<20;i++)
    	for(j=0;j<20;j++)
    	{
    		var1.at<Vec3b>(i,j)[0]=255;
    		var1.at<Vec3b>(i,j)[1]=0;
    		var1.at<Vec3b>(i,j)[2]=0;
    	}
    for(i=20;i<40;i++)
    	for(j=0;j<20;j++)
    	{
    		var1.at<Vec3b>(i,j)[1]=255;
    		var1.at<Vec3b>(i,j)[0]=0;
    		var1.at<Vec3b>(i,j)[2]=0;
    	}
    for(i=40;i<60;i++)
    	for(j=0;j<20;j++)
    	{
    		var1.at<Vec3b>(i,j)[2]=255;
    		var1.at<Vec3b>(i,j)[1]=0;
    		var1.at<Vec3b>(i,j)[0]=0;
    	}
    for(i=60;i<80;i++)
    	for(j=0;j<20;j++)
    	{
    		var1.at<Vec3b>(i,j)[2]=255;
    		var1.at<Vec3b>(i,j)[1]=255;
    		var1.at<Vec3b>(i,j)[0]=255;
    	}
    for(i=80;i<100;i++)
    	for(j=0;j<20;j++)
    	{
    		var1.at<Vec3b>(i,j)[2]=0;
    		var1.at<Vec3b>(i,j)[1]=0;
    		var1.at<Vec3b>(i,j)[0]=0;
    	}
	setMouseCallback("windows1", CallBackFunc, NULL);
	imshow("windows1",var1);
	waitKey(10);
    }
	return 0;
}