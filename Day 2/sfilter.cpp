#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main()
{
	Mat var2 = imread("image.jpg",1);
	namedWindow("window2",WINDOW_AUTOSIZE);
	imshow("window2",var2);
	Mat var1(var2.rows,var2.cols,CV_8UC3,Scalar(0,0,0));
	int i,j,a,b,c,r,sumB1,sumG1,sumR1,sumB2,sumG2,sumR2;
	int ker1[3][3];
	int ker2[3][3];
	
	ker1[0][0] = -1;
	ker1[0][1] = 0;
	ker1[0][2] = 1;
	ker1[1][0] = -2;
	ker1[1][1] = 0;
	ker1[1][2] = 2;
	ker1[2][0] = -1;
	ker1[2][1] = 0;
	ker1[2][2] = 1;
	
	ker2[0][0] = 1;
	ker2[0][1] = 2;
	ker2[0][2] = 1;
	ker2[1][0] = 0;
	ker2[1][1] = 0;
	ker2[1][2] = 0;
	ker2[2][0] = -1;
	ker2[2][1] = -2;
	ker2[2][2] = -1;
	
	for( i = 0; i < var2.cols; i++)
	{
		
		for(j = 0; j < var2.rows ; j++)
		{
			var1.at <Vec3b>(j,i)[0] = var2.at <Vec3b>(j,i)[0];
			var1.at <Vec3b>(j,i)[1] = var2.at <Vec3b>(j,i)[1];
			var1.at <Vec3b>(j,i)[2] = var2.at <Vec3b>(j,i)[2];
		}
	}
		
	for( i = 1; i < var2.cols-1; i++)
	{
		
		for(j = 1; j < var2.rows-1; j++)
		{
		
			/*a = var2.at <Vec3b>(j,i)[0];
			b = var2.at <Vec3b>(j,i)[1];
			c = var2.at <Vec3b>(j,i)[2];*/
			int mb1=0,mg1=0,mr1=0,mb2=0,mg2=0,mr2=0;
			
			for(r = i-1; r < i + 2; r++)
			{
				for(c = j-1; c < j+2; c++)
				{
					sumB1 = ker1[c-j+1][r-i+1] * var2.at <Vec3b>(c,r)[0];
					sumG1 = ker1[c-j+1][r-i+1] * var2.at <Vec3b>(c,r)[1];
					sumR1 = ker1[c-j+1][r-i+1] * var2.at <Vec3b>(c,r)[2];
					
					mb1 = mb1 + sumB1;
					mg1 = mg1 + sumG1;
					mr1 = mr1 + sumR1;
					
					sumB2 = ker1[c-j+1][r-i+1] * var2.at <Vec3b>(c,r)[0];
					sumG2 = ker1[c-j+1][r-i+1] * var2.at <Vec3b>(c,r)[1];
					sumR2 = ker1[c-j+1][r-i+1] * var2.at <Vec3b>(c,r)[2];
					
					mb2 = mb2 + sumB2;
					mg2 = mg2 + sumG2;
					mr2 = mr2 + sumR2;
				}
			}
			
			int mg,mb,mr;
			mg = sqrt(mg1 * mg1 + mg2 * mg2);
			mb = sqrt(mb1 * mb1 + mb2 * mb2);
			mr = sqrt(mr1 * mr1 + mr2 * mr2);
			
			if(mg < 0) mg = 0;
			if(mg > 255) mg = 255;
			if(mr < 0) mr = 0;
			if(mr > 255) mr = 255;
			if(mb < 0) mb = 0;
			if(mb > 255) mb = 255;
			
			
			
					var1.at <Vec3b>(j,i)[0] = mb;
					var1.at <Vec3b>(j,i)[1] = mg;
					var1.at <Vec3b>(j,i)[2] = mr;
			
			
			}
	}
	
	
	
	
	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1",var1);
	
	waitKey(0);
	
}
