#include "tempclass.h"
#include <iostream>
#include <string>
#include "starvesingle.h"
#include "lazysingle.h"
#include "templazy.h"
#include "lazyderive.h"
using namespace std;
int main()
{
	//implicit instanition 隐式初始化
	TempClass<int> tmpc1(2048);
	cout << tmpc1.GetData() << endl;
	tmpc1.SetData(52);

	TempClass<int> tmpc2(222);
	cout << tmpc2.GetData() << endl;

	auto tmpstr = TempString<char, 20>();
	tmpstr.GetInfo();
	//模板默认类型T2 = int
	auto dfclass = DefaultClass<char>(100);

	//模板的调用按照实现程度最高的调用,调用具体化模板
	NormalTemp<int, char *>  nt1 (1024, "Hello World!!");
	nt1.PrintData();

	//调用偏特化模板
	NormalTemp<double, char *> nt2(1.34, "paritial");
	nt2.PrintData();

	//普通模板
	NormalTemp<double, string> nt3(1.78, "normal temp");
	nt3.PrintData();

	//饿汉单利模式调用
	auto s1 = StarveSingle::GetInstance();
	auto s2 = StarveSingle::GetInstance();
	cout << s1 << endl;
	cout << s2 << endl;

	//懒汉单利模式调用
	auto lz1 = LazySingle::GetInstance();
	auto lz2 = LazySingle::GetInstance();
	cout << lz1 << " " << lz2 << endl;
	//需要手动调用析构函数回收资源
	if (lz1 != nullptr) {
		delete lz1;
		lz1 = nullptr;
	}
	cout << lz1 << " " << lz2 << endl;
	//多次调用会造成崩溃
  	//delete lz2;
	auto la1 = LazyAuto::GetInstance();
	auto la2 = LazyAuto::GetInstance();
	cout << la1 << " " << la2 << endl;
	//不需要手动释放，智能指针自己释放

	auto autop1 = LazySafeAuto::GetInstance();
	auto autop2 = LazySafeAuto::GetInstance();
	cout << autop1 << " " << autop2 << endl;

	//测试我们实现的单利模板，内置类型int
	auto tmplazy1 = TempLazy<int>::GetInstance();
	auto tmplazy2 = TempLazy<int>::GetInstance();
	cout << tmplazy1 << " " << tmplazy2 << endl;

	//复杂类型继承模板类型，然后关闭公有的构造函数
	auto tmpd1 = LazyDerive::GetInstance();
	auto tmpd2 = LazyDerive::GetInstance();
	cout << tmpd1 << " " << tmpd2 << endl;
	getchar();
    return 0;
}

