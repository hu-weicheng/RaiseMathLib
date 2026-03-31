//#pragma execution_character_set("utf-8")

#include <windows.h>
#include <iostream>
//#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/core/version.hpp>
//#include <opencv4/opencv2/core/utility.hpp>

using namespace std;

//项目--属性--C/C++ ---命令行--附加选项：/utf-8
int main() 
{
    //SetConsoleOutputCP(CP_UTF8);  // 设置控制台输出为 UTF-8
	//system("chcp 65001"); // 设置控制台输出为 UTF-8
	system("chcp 936"); // 设置控制台输出为 UTF-8
	std::wcout.imbue(std::locale("chs")); // 设置 wcout 使用系统默认的区域设置
    std::wcout << L"OpenCV 主版本: " << CV_MAJOR_VERSION << std::endl;
    std::wcout << "OpenCV 次版本: " << CV_MINOR_VERSION << std::endl;
    std::wcout << "OpenCV 补丁版本: " << CV_SUBMINOR_VERSION << std::endl;

	wstring s;
	wcin.imbue(std::locale("chs")); // 设置 wcin 使用系统默认的区域设置
	wcin >> s;
	wcout << L"你输入的字符串是: " << s << std::endl;

	return 0;
}