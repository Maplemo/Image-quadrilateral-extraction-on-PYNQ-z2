/*
The ImgProjection IP is one of the module of Xilinx summer school project "Image quadrilateral extraction on PYNQ-z2"
https://github.com/Maplemo/Image-quadrilateral-extraction-on-PYNQ-z2
KK 2020.7.29
*/
#ifndef _IMGPROJECTION_
#define _IMGPROJECTION_

#include "hls_video.h"
#include <ap_fixed.h>

struct wide_stream {
	ap_uint<32> data;
	ap_uint<1> user;
	ap_uint<1> last;
};
#define MAX_WIDTH  1080
#define MAX_HEIGHT 1920
#define CHANNEL	   3
#define N 10


// typedef video library core structures
typedef hls::stream<ap_axiu<32,1,1,1> > AXI_STREAM;
typedef hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_8UC3> RGB_IMAGE;
typedef hls::Scalar<3, unsigned char>                 RGB_PIXEL;

typedef hls::Scalar<1, unsigned char>                 GRAY_PIXEL;
typedef hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_8UC1>     GRAY_IMAGE;
typedef hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_16SC1>    GRAY_IMAGE_16S;
typedef hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_16UC1>    GRAY_IMAGE_16;

void ImgProjection(AXI_STREAM& in_stream, AXI_STREAM& out_stream,
		ap_uint<32> hight, ap_uint<32> width,
		ap_uint<32> x0,ap_uint<32> x1,ap_uint<32> x2,ap_uint<32> x3,
		ap_uint<32> y0,ap_uint<32> y1,ap_uint<32> y2,ap_uint<32> y3);

#endif
