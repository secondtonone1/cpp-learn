// lambda.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include "lamclass.h"
using namespace std;
//测试生命周期
void scopTest(LamClass &lamClass){
	int a = 200;
	int b = 300;
	lamClass.PushFunc([&](int a1, int b1)->void{
		std::cout << "a address is " << &a <<endl;
		std::cout << "b address is " << &b << endl;
		std::cout << "a value is " << a << endl;
		std::cout << "b value is " << b << endl;
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
	
	//捕获a,b引用，将函数放入队列
	LamClass lamClass;
	lamClass.PushFunc([&](int a1, int b1)->void{
		std::cout << "a address is " << &a <<endl;
		std::cout << "b address is " << &b << endl;
		std::cout << "a value is " << a << endl;
		std::cout << "b value is " << b << endl;
		cout << "add res is " << a1 + b1 << endl;
	} );
	//由于a,b在当前作用域未释放，所以可以正常输出a,b的值。
	FuncType m;
	if (lamClass.PopFunc(m) == true){
		m(5,6);
	}
	//scopTest函数里lambda捕获的是scopTest函数中的a,b引用
	//scopTest调用结束后，a,b空间释放
	scopTest(lamClass);
	//a,b空间释放后，此时PopFunc返回 函数，输出a,b的值为乱码
	if (lamClass.PopFunc(m) == true){
		m(7,8);
	}
	//所以lambda表达式捕获变量引用，一定要注意变量生命周期的问题。
	getchar();
	return 0;
}

