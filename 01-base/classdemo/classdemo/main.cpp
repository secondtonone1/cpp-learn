// classdemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "classdemo.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//�޲ι��캯�������ֵ��÷�ʽ
	ClassDemo classdemo;
	//ClassDemo classdemo = ClassDemo();
	classdemo.PrintInfo();

	auto classdemo2 = ClassDemo("zack",31);
	classdemo2.PrintInfo();
	getchar();
	return 0;
}

