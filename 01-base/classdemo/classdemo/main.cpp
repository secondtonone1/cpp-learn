// classdemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "classdemo.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//无参构造函数的两种调用方式
	ClassDemo classdemo;
	//ClassDemo classdemo = ClassDemo();
	classdemo.PrintInfo();

	auto classdemo2 = ClassDemo("zack",31);
	classdemo2.PrintInfo();
	getchar();
	return 0;
}

