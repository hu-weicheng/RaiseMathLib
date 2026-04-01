#include <direct.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

//debug下在lib文件的名称后加d，release下不加d。




int main()
{
	system("chcp 65001");
	//setlocale(LC_ALL, ""); // ✅ 辅助解决本地化字符问题

	// 打印当前工作目录
	char buffer[256];
	_getcwd(buffer, 256);
	std::cout << "当前工作目录: " << buffer << std::endl;

	string file = "test.jpg";
	// 打印 OpenCV 构建信息
	//std::cout << cv::getBuildInformation() << std::endl;

	Mat img = imread(file);//

	if (img.empty())
	{
		std::cout << "image read is null" << std::endl;
		return -10;
	}


	/*namedWindow("【原图】", WINDOW_AUTOSIZE);*/
	imshow("【原图】", img);

	waitKey(0);
	return 0;
}
