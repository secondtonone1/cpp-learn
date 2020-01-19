// stringdomo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	std::string name, job;
	cout << "Please input your name" <<endl;
	cin >> name;
	cout << "Please input your job" <<endl;
	cin >> job;
	cout << "your name is "<<name << " your job is "<< job <<endl;
	//16位
	short i = 100;
	cout << "sizeof(short )" << sizeof(i) << endl;
	//32位
	int j = 120;
	cout << "sizeof(int)" <<sizeof(j) <<endl;
	//32位
	long k = 130;
	cout << "sizeof(long)" <<sizeof(k) <<endl;
	
	//利用stringstream拼接字符串
	stringstream strstreams;
	strstreams << "hello ";
	strstreams << "world ";
	cout << "string conncet is :"<<strstreams.str() <<endl;
	//清空stringstream
	strstreams.str("");
	cout << "after clear is : "<<strstreams.str() <<endl;

	string istr= "";
	//利用stringstream转换类型
	stringstream convstream;
	convstream << i ;
	convstream >> istr;
	cout << "istr is " <<istr<<endl;
	//多次转换要注意清空stream
	convstream.str("");
	convstream.clear();
	convstream << 3.1415;
	convstream >> istr;
	cout << "istr is " <<istr<<endl;

	//c11转化
	string convstr = to_string(95.27);
	cout << "conv string is : " << convstr <<endl;
	float fnum = stof(convstr);
	//类似的还有stoi
	cout << "fnum is : " << fnum <<endl;
	//没有'\0'的char数组不是string, cout输出会有乱码
	char msg[5]={'a','b','c','d','e'};
	//有'\0'的字符数组等同于字符串
	char msg2[5]={'a','b','c','d','\0'};
	cout << "msg is : "<<msg2<< endl;
	//由于没有'\0'，strlen计算的长度是错误的
	//cout << strlen(msg) <<endl;
	//strlen是找到\0才结束
	cout << "msg len is " << strlen(msg2) <<endl;

	//c98字符串初始化
	auto str1 = "hello world!!!";
	char str2[20] = "hello world2!";
	//c11 字符串初始化
	char str3[] = {"hello world3"};
	cout << str1 <<endl;
	cout << str2 << endl;
	cout << str3 <<" "<< strlen(str3) << endl;
	//赋值和拼接
	convstr = convstr+"zack";
	cout << convstr <<endl;
	//C风格拼接数组与copy数组
	char charray[15]={};
	strcpy_s(charray, str2);
	char charray2[40]={};
	cout << charray <<endl;
	strcat_s(charray2, charray);
	cout << charray2 <<endl;
	cout << sizeof(str3) <<endl;
	cout << sizeof(str2) <<endl;
	cout << convstr.length() <<endl;
	system("pause");
	return 0;
}

