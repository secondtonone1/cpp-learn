// operatordemo.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <string>
#include "mystring.h"
#include "baseclass.h"
#include "friendclass.h"
using namespace std;

int main()
{
	MyString mystring("hello world !", strlen("hello world !"));
	cout << mystring << endl;

	MyString mystring2(mystring);
	cout << mystring2 << endl;

	cout << mystring + mystring2 << endl;

	MyString mystring3("My name is zack!", strlen("My name is zack!"));
	cout << mystring3 << endl;
	mystring2 = mystring3;
	mystring3 = mystring;
	cout << "mystring2 is : "<<mystring2 << endl;
	cout << "mystring3 is : " << mystring3 << endl;
	if (mystring2 < mystring) {
		cout << "mystring is bigger" << endl;
	}
	else {
		cout << "mystring3 is bigger" << endl;
	}

	MyString mystring4 = "nothing seriouse";
	cout << mystring4 << endl;

	//初始化基类对象
	BaseClass bc = BaseClass(2, 1024, "BaseClass");
	//初始化子类对象
	DeriveClass dc = DeriveClass(105, 202, 403, "DeriveClass");
	//输出基类中的static变量
	cout << BaseClass::m_snum << endl;
	//输出子类中的static变量
	cout << DeriveClass::m_snum << endl;
	//将子类对象赋值给基类引用
	BaseClass & rbc = DeriveClass(105, 202, 403, "DeriveClass");
	//基类类型的引用，可以访问基类的成员
	cout << rbc.m_nAge << endl;
	//不可以访问子类的成员
	//rbc.m_nscore;
	//基类类型的引用，此时引用的是子类对象，调用虚函数会调用子类实现的功能
	rbc.PrintClassData();
	//基类类型的引用变量调用普通的函数,实际调用的是基类函数
	rbc.Overloadf();
	//子类对象调用普通的函数，调用的是子类的函数，因为基类的函数被隐藏了。
	dc.Overloadf();

	//考察指针调用，多态
	BaseClass *pBase = new DeriveClass(1024, 2048, 512, "hello world");
	pBase->PrintClassData();
	pBase->Overloadf();
	//类型转换
	DeriveClass* pDerive =  dynamic_cast<DeriveClass*>(pBase);
	pDerive->PrintClassData();
	pDerive->Overloadf();
	//总结下，考察对象调用的是哪个函数，首先看对象是指针(引用)还是普通对象。
	//1  如果是普通对象，无论调用虚函数还是普通函数，都调用的是子类的函数，
	//当然子类没有实现该函数，则调用的是基类的函数。
	// 2 如果是指针或者引用，且其是子类类型指针或引用，那么调用的就是子类的函数
	//当然子类没实现该函数，则调用的是基类函数。这点和1一样。
	// 3 如果是子类指针或引用，指向基类对象，那么调用虚函数是多态效果，也就是
	//调用子类的实现函数，如果调用普通函数，则是基类的实现函数。
	
	//重载是指在一个类里同名函数参数不同
	//覆盖(重写)override, 基类虚函数在子类重写，其参数返回值类型等都相同，如果子类实现基类的同名虚函数，
	//但是参数不同，则会造成基类虚函数的隐藏，而非虚函数覆盖。
	//重定义隐藏 redifine 指子类实现了基类的同名函数，不要求实现的函数和基类形参类型相同，造成基类函数被隐藏

	//子类无法调用基类实现的NetWork，因为基类函数被隐藏了
	//pDerive->NetWork();
	//子类可以调用自己实现的NetWork函数
	pDerive->NetWork(126);
	//同样，子类也无法调用基类的GreetClient(str)，这就是隐藏的效果，只能调用自己的GreetClient(int)
	//pDerive->GreetClient("Hello World");
	pDerive->GreetClient(204);
	//子类调用基类隐藏的函数有两种方式，1 动态转换为基类类型 2或者将子类类型转化为基类调用函数即可。
	BaseClass* pBase2 = dynamic_cast<BaseClass*>(pDerive);
	pBase2->GreetClient("Hello QBYC");
	pBase2->NetWork();
	//通过子类函数内部实现BaseClass::GreetClient调用
	pDerive->CallBaseGreetClient("Hello tao");
	//如果这时将pDerive继续转化为基类指针
	pBase = dynamic_cast<BaseClass*>(pDerive);
	//调用虚函数PrintClassData，则会多态。
	pBase->PrintClassData();

	//通过基类指针指向子类对象，调用BaseExec
	//由于Overload为普通函数，pBase调用基类的Overload,指针是什么类型就调用对应的实现函数，除非是虚函数重写构成多态
	//而PrintClassData为虚函数，pBase内部的虚函数表重写了PrintClassData，则调用子类的PrintClassData
	pBase->BaseExec();
	//构造一个子类对象
	DeriveClass drclass = DeriveClass();
	//子类对象调用BaseExec
	//由于子类对象没有实现BaseExec，所以会调用基类的BaseExec
	//调用基类的BaseExec时，C++自动做了隐式转换 DeriveClass转换为BaseClass 
	//所以调用Overload这个普通的成员函数时我们考察的是调用时的类型为BaseClass，此时调用的为基类的Overload
	//调用PrintClassData函数是考察实际类型为DeriveClass，DeriveClass虚函数表重写了该函数，此时调用的是子类的PrintClassData
	drclass.BaseExec();
	//final 函数调用的都是基类的
	pDerive->BaseC11();
	pBase->BaseC11();
	//调用子类虚函数
	pBase->OverrideC11();
	//析构函数写成虚函数，这样delete 基类指针可以实现先调用子类析构再调用基类析构的功能
	delete pBase;
	//虚函数，类的静态成员，类的静态成员函数都不占用空间
	//一个类对象的大小遵循对齐和补齐原则
	//其次如果该类有虚函数，则类对象的大小会多四字节指针，指向虚函数表，虚函数存在虚函数表里
	//所以一个有虚函数的类对象，其内存构成为起始的四字节存储虚函数表地址，接下来的字节遵循
	//对齐和补齐的原则，如果该类多重继承，则根据基类是否有虚函数，如果有就额外增加四字节，因为
	//不同的基类虚函数要存在不同的表里，所以就会有多个指向虚函数表的指针，那就有多个四字节。
	//具体文档和测试可以看我的技术博客 https://www.limerence2017.com/2017/08/03/cppvirtual/

	//友元类可以访问其他类的私有成员
	auto friendcl = FriendClass();
	auto privatecl = PrivateClass();
	friendcl.DealPrivateClass(privatecl);
	getchar();
    return 0;
}

