// lambda.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include <iostream>
#include "lamclass.h"
using namespace std;
//������������
void scopTest(LamClass &lamClass){
	int a = 200;
	int b = 300;
	lamClass.PushFunc([&](int a1, int b1)->void{
		std::cout << "a address is " << &a <<endl;
		std::cout << "b address is " << &b << endl;
		cout << "add res is " << a1 + b1 << endl;
	} );
}

int main(int argc, char* argv[])
{
	int a = 100;
	int b = 200;
	[&](int a1, int b1)->void{
		std::cout << "a address is " << &a <<endl;
		std::cout << "b address is " << &b << endl;
	} (3,4);
	
	LamClass lamClass;
	lamClass.PushFunc([&](int a1, int b1)->void{
		std::cout << "a address is " << &a <<endl;
		std::cout << "b address is " << &b << endl;
		cout << "add res is " << a1 + b1 << endl;
	} );

	FuncType m;
	if (lamClass.PopFunc(m) == true){
		m(5,6);
	}
	scopTest(lamClass);
	if (lamClass.PopFunc(m) == true){
		m(7,8);
	}
	getchar();
	return 0;
}

