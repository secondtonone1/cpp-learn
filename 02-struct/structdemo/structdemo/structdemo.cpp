// structdemo.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
struct Student{
	char m_name[10];
	int age;
	int score;
	short sex;
};

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << sizeof(int) <<" "<< sizeof(short)<<std::endl;
	Student s1={"zack",31,100,0};
	std::cout << "s1 size is "<<sizeof(s1)<<std::endl;
	cout << &s1 <<endl;
	cout <<&s1.m_name<<endl;
	cout << & s1.age << endl;
	cout << &s1.score <<endl;
	cout <<&s1.sex <<endl;
	//结构体对齐和补齐标准
	//对齐如果该数据类型大于4字节，则按照4字节计算对齐，否则按照实际类型大小对齐
	//如果数据存放的位置不是自身大小的整数倍则需要移动n个字节，使该成员起始位置
	//为自身字节大小的整数倍
	//如果结构体整体大小不是最大成员类型字节(大于4字节按照4字节)的整数倍，则补齐至整数倍。
	// m_name 10字节 + 对齐2字节 + age四字节 + score四字节 + sex两个字节 = 22字节
	// 22 不是4的倍数，则补齐2字节，变为24
	system("pause");
	return 0;
}

