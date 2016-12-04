#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main()
{
	Mat var1 = imread("index1.jpeg",1);
	
	int i,j,a,b,c,max = -1;
	int R[256],G[256],B[256];
	
	int k;
	for(k = 0; k < 256;k++)
	{
		R[k] = 0;
		G[k] = 0;
		B[k] = 0;
	}
	
	
	for( i = 0; i < var1.cols; i++)
	{
		
		for(j = 0; j < var1.rows ; j++)
		{
		
			a = var1.at <Vec3b>(j,i)[0];
			b = var1.at <Vec3b>(j,i)[1];
			c = var1.at <Vec3b>(j,i)[2];
			
			B[a]++;
			G[b]++;
			R[c]++;
			
			if(max < R[c])
			{
				max = R[c];
			}
			
			if(max < G[b])
			{
				max = G[b];
			}
			
			if(max < B[a])
			{
				max = B[a];
			}
			
			
			}
	}
	
	/*for(k = 0; k < 256;k++)
	{
		R[k] = (R[k] / max)*100;
		G[k] = (G[k] / max)*100;
		B[k] = (B[k] / max)*100;
	}*/
	
	
	
	Mat var2(max,256,CV_8UC3,Scalar(0,0,0));
	for( i = 0; i < var2.cols; i++)
	{
		var2.at <Vec3b>(B[i],i)[0] = 255;
		var2.at <Vec3b>(G[i],i)[1] = 255;
		var2.at <Vec3b>(R[i],i)[2] = 255;
		
	}
	
	namedWindow("window2",WINDOW_AUTOSIZE);
	imshow("window2",var2);
	
	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1",var1);
	
	waitKey(0);
	return 0;
}
