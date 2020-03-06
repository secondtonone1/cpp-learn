#include "lambdademo.h"
#include <utility>
#include <vector>
#include <algorithm>
void use_lambda() {
	std::vector<int> numbers = { 12,14,25,27,30,3,2 };
	std::count_if(numbers.begin(), numbers.end(), [](int a) {
		return a % 3 == 0;
	});
	int nouter = 3;
	//lambda可以捕获外界变量的值, 可以直接传递参数调用，但是函数体内无法修白nouter的值，因为nouter捕获后变为右值。
	int res = [nouter](int m)->int { return  nouter + m; }(1024);
	cout << "res is " << res << endl;
	//lambda可捕获外部变量的引用，可以在函数内部修改nouter引用的数值，从而达到修改nouter的目的。
	res = [&nouter](int m)->int {nouter = m;  return nouter + m; }(1024);
	cout << "nouter is " << nouter << endl;
	cout << "res is " << res << endl;
	int nother = 5;
	string strname = "zack";
	//lambda可以通过=捕获所有的变量值
	//=捕获其他变量的值，&strname捕获strname的引用
	res = [=, &strname](string name) {
		strname = name + " " + strname;
		return nouter + nother;
	}("hello world");
	cout << "strname is " << strname << endl;
	cout << "res is " << res << endl;

	//&捕获其他所有变量的引用, strname捕获值
	auto strres = [&, strname](string name) {nouter = 1; nother = 7;  return  strname + " " + name; }("hello world ");
	cout << "nouter is " << nouter << endl;
	cout << "strres is " << strres << endl;
	cout << "nother is " << nother << endl;
}

//lambda捕获局部变量，要考虑局部变量的生命周期，
//如果局部变量被释放，而lambda函数被调用会出现问题
void push_func(LambQueue & funque) {
	//局部变量，push_func函数结束后该变量释放
	int temp1 = 1;
	int temp2 = 3;
	cout << &temp1 << " " << &temp2 << endl;
	//lamfun捕获局部变量，我们测试捕获的变量生命周期
	//捕获temp1和temp2，并将lamfun放入队列中
	auto lamfun = [&](int a, int b) {
		cout << &temp1 << " " << &temp2 << endl;
		cout << a << " " << b << " " << temp1 << " " << temp2 << " " << endl;
		return a + b + temp1 + temp2;
	};
	//temp1， temp2被捕获，且lambda函数被放入队列
	//temp1, temp2会随着push_func运行到}后释放
	funque.push_back(lamfun);
}

void test_lambdalife() {
	LambQueue funque;
	push_func(funque);
	//push_func调用结束后内部的局部变量释放了
	lambfunc lf;
	bool bres = funque.pop_front(lf);
	//所以此时pop_front返回的函数输出捕获push_func内部的变量，因为局部变量已经被释放，会出现乱码
	if (bres) {
		auto data = lf(5, 7);
		cout << data << endl;
	}
}