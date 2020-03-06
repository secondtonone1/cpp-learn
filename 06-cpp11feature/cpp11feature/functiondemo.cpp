#include "functiondemo.h"
#include <utility>
#include <vector>
#include <algorithm>

int add(int a, int b) {
	return  a + b;
}

void use_funclass() {
	//定义函数对象
	FunctionClass funclass;
	//由于operator()被定义了，所以类对象可以当作函数使用
	int res = funclass(5, 6);
	cout << res << endl;
	//函数指针类型定义函数指针
	functype funcp = add;
	res = funcp(100, 200);
	cout << res << endl;
	//我们定义一个函数指针
	int(*funcp2)(int, int) = add;
	res = funcp2(300, 400);
	cout << res << endl;

	//typedef 定义了一种类型，如typedef unsigned int  uint 就是定义了一种新的类型
	//而int  uint 则是定义了一个变量
	//同样的道理 typedef int(*funcp)(int, int) 定义了funcp为函数指针类型
	//int (*funcp)(int, int)定义了函数指针变量

	functype2  funcp3 = add;
	res = funcp3(200, 200);
	cout << res << endl;

	functype3 funcp4 = add;
	res = funcp4(102, 102);
	cout << res << endl;
}

void use_function() {
	//定义一个function对象，调用全局函数
	function<int(int, int)> funcob = add;
	int res = funcob(1024, 1024);
	cout << res << endl;
	FunctionClass classobj;
	//定义function对象调用函数对象
	function<int(int, int)> classob = classobj;
	res = classob(200, 300);
	cout << res << endl;
	//function对象调用lambda表达式
	function<bool(int)> compareob = [&res](int m) {
		return res > m;
	};
	bool bres = compareob(200);
	cout << bres << endl;
	//function对象调用模板类
	function<int(int, int)> minusob = TempClass<int>();
	res = minusob(100, 50);
	cout << res << endl;
	//调用类的静态成员函数
	function<int(int, int)> mulob = FunctionClass::multi;
	res = mulob(3, 5);
	cout << res << endl;

	//调用类的成员
	function<int(FunctionClass&)>f = &FunctionClass::m_num;
	FunctionClass funcobj2;
	cout << f(funcobj2) << endl;
	
	//绑定类的成员函数，返回类型为void类型

	FunctionDemo  funcdm;
	function<void ( int, int)> fpadd = std::bind(&FunctionDemo::print_add, funcdm, placeholders::_1, placeholders::_2);
	fpadd(3, 4);
	//返回类型为其他类型如string类型的函数，绑定时我们用auto，
	//否则写成function<string(string, string)>会出问题
	auto fsstract = std::bind(&FunctionDemo::constract_str, & funcdm, placeholders::_1, placeholders::_2);
	fsstract("Hello", " World!");
	//绑定类的静态函数
	function<int(int, int)> fstatic = std::bind(&FunctionClass::multi, placeholders::_1, placeholders::_2);
	fstatic(200, 90);
}
