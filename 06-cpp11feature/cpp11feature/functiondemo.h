#ifndef  __FUNCTION_DEMO_H__
#define __FUNCTION_DEMO_H__
#include <string>
#include <iostream>
#include <list>
#include <functional>
using lambfunc = std::function<int(int a, int b)>;
using namespace std;

class FunctionClass {
public:
	FunctionClass() { m_num = 0; }
	int operator ()(int a, int b) {
		return a + b;
	}
	static int multi(int a, int b) {
		return a*b;
	}
	
	int m_num;
};

class FunctionDemo {
public:
	FunctionDemo() = default;
	void constract_str(string a, string b) {
		cout << a + b << endl;
	}
	void print_add(int a, int b)  {
		cout << "a+b  " << a + b << endl;
	}
};

template<typename T>
class TempClass {
public:
	TempClass() = default;
	int operator()(T a, T b) {
		return a - b;
	}
};

//定义函数指针类型, functype为函数指针类型，指向int  func(int, int)类型的函数
typedef  int(*functype)(int, int);
//通过typdef function类型定义函数对象
typedef function<int(int, int)>  functype2;
//using 定义新的类型
using functype3 = function<int(int, int)>;
extern void use_funclass();
extern void use_function();
#endif // __FUNCTION_DEMO_H__


