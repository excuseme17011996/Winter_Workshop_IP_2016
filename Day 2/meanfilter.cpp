#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main()
{
	Mat var2 = imread("image.jpg",1);
	Mat var1(var2.rows,var2.cols,CV_8UC3,Scalar(0,0,0));
	int i,j,a,b,c,r,sumB,sumG,sumR;
	int ker[3][3];
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			ker[i][j] = 1;
		}
	}
	
	for( i = 0; i < var2.cols; i++)
	{
		
		for(j = 0; j < var2.rows ; j++)
		{
			var1.at <Vec3b>(j,i)[0] = var2.at <Vec3b>(j,i)[0];
			var1.at <Vec3b>(j,i)[1] = var2.at <Vec3b>(j,i)[1];
			var1.at <Vec3b>(j,i)[2] = var2.at <Vec3b>(j,i)[2];
		}
	}
	int cou = 3;
	while(cou--){	
	for( i = 1; i < var2.cols-1; i++)
	{
		
		for(j = 1; j < var2.rows-1; j++)
		{
		
			/*a = var2.at <Vec3b>(j,i)[0];
			b = var2.at <Vec3b>(j,i)[1];
			c = var2.at <Vec3b>(j,i)[2];*/
			int mb=0,mg=0,mr=0;
			
			for(r = i-1; r < i + 2; r++)
			{
				for(c = j-1; c < j+2; c++)
				{
					sumB = ker[c-j+1][r-i+1] * var2.at <Vec3b>(c,r)[0];
					sumG = ker[c-j+1][r-i+1] * var2.at <Vec3b>(c,r)[1];
					sumR = ker[c-j+1][r-i+1] * var2.at <Vec3b>(c,r)[2];
					
					mb = mb + sumB;
					mg = mg + sumG;
					mr = mr + sumR;
				}
			}
			
			
			mb=mb/9;
			mr=mr/9;
			mg=mg/9;
			
			
					var1.at <Vec3b>(j,i)[0] = mb;
					var1.at <Vec3b>(j,i)[1] = mg;
					var1.at <Vec3b>(j,i)[2] = mr;
			
			
			}
	}
	var2 = var1;
	}
	namedWindow("window2",WINDOW_AUTOSIZE);
	imshow("window2",var2);
	
	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1",var1);
	
	waitKey(0);
	
}
