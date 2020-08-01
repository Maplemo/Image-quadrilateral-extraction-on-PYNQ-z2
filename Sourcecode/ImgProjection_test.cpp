#include <cassert>
#include <iostream>
#include <stdio.h>
#include <hls_opencv.h>

#include "ImgProjection.h"

#define INPUT_IMG "E:/test1.jpg"
#define OUTPUT_IMG "E:/testout.jpg"

using namespace std;
using namespace cv;

int main()
{

	ap_uint<12> x[4]={391,505,836,637};
	ap_uint<12> y[4]={302,526,273,34};
	int hight=540,width=960;
	Mat imgSrc = imread(INPUT_IMG,IMREAD_COLOR);;
	AXI_STREAM input;
	AXI_STREAM output;
	Mat imgOut = Mat(hight,width,CV_8UC3);
	cvMat2AXIvideo(imgSrc,input);

	ImgProjection(input, output, hight, width,x[0],x[1],x[2],x[3],y[0],y[1],y[2],y[3]);

    AXIvideo2cvMat(output, imgOut);

    imwrite(OUTPUT_IMG, imgOut);

}
