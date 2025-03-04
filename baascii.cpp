// baascii.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <algorithm>
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include "baascii.h"
#include "stb_image.h"
#include <regex>
float rgb2b(float r, float g, float b) {
	return roundToNearest05(std::max({ r, g, b }));
}
float roundToNearest05(float value) {
	return std::round(value * 20) / 20.0f;
}
float rgb2b(int c) {
	return static_cast<float>(std::max({ c & 0xff0000 >> 16 , c & 0xff00 >> 8, c & 0xff })) / 255.0f;
}
std::vector<std::string> stringSplit(const std::string& str, char delim) {
	std::string s;
	s.append(1, delim);
	std::regex reg(s);
	std::vector<std::string> elems(std::sregex_token_iterator(str.begin(), str.end(), reg, -1),
		std::sregex_token_iterator());
	return elems;
}
int main()
{
	std::ifstream dataFile;
	dataFile.open("data.txt", std::ios::in);
	if (!dataFile.is_open())
	{
		std::cerr << "cannot open the file";
	}
	char buf[1024] = { 0 };
	while (dataFile.getline(buf, sizeof(buf)))
	{
		std::vector<std::string> elems = stringSplit(buf, '|');
		std::cout << buf << std::endl;
		for (std::string elem, elems) {
			std::cout << elems[1] << std::endl;
		}
	}
	std::cout << "Hello World!\n";
	std::cout << rgb2b(0, 0, 25.51) << std::endl;
	std::cout << rgb2b(0x00aa00ff) << std::endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件