# Image-quadrilateral-extraction-on-PYNQ-z2
Xilinx Summer School Project
### Board
PYNQ-z2  
### Version of Vivado
Vivado 2018.3  
### File
/Sourcecode:投影变换算法HLS实现源代码，已完成测试和优化  
/ExecutableFiles：可执行文件，包括比特流和tcl文件，目前测试未通过
## 项目概况
本项目实现软件从SD卡中读取包含四边形提取目标的图片，经灰度化处理后，使用硬件部分的边缘提取模块对图像进行边缘检测提取，软件再利用边缘检测的结果找到目标四边形的轮廓，根据这一轮廓确定四边形的四个顶点（角点）坐标。之后再调用硬件部分的投影变换模块，向模块输入角点的坐标，模块根据坐标对应到新的图像的四个顶点得到变换矩阵，用原始图像的坐标和变换矩阵相乘就能得到变换图像对应的坐标，生成变换图像之后，模块将图像输出到软件端存储。项目的系统框图如下图所示。
![流程图](https://github.com/Maplemo/Image-quadrilateral-extraction-on-PYNQ-z2/blob/master/image/%E6%B5%81%E7%A8%8B%E5%9B%BE.png)  
  
下面分别给出了处理效果，图片从上到下分别是：原始图像；硬件实现边缘提取之后软件通过轮廓提取确定的纸张顶点（角点），灰度图中标记了角点，其上方的数组输出是角点的坐标信息；硬件实现的投影变换算法输入角点信息和原始图像之后输出的变换图像。  
![流程图](https://github.com/Maplemo/Image-quadrilateral-extraction-on-PYNQ-z2/blob/master/image/%E5%8E%9F%E5%9B%BE.jpg)  
  
![流程图](https://github.com/Maplemo/Image-quadrilateral-extraction-on-PYNQ-z2/blob/master/image/%E8%A7%92%E7%82%B9.png)  
  
![流程图](https://github.com/Maplemo/Image-quadrilateral-extraction-on-PYNQ-z2/blob/master/image/%E6%88%AA%E5%8F%96.jpg)  
  
