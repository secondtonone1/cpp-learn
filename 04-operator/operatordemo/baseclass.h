#ifndef __BASE_CLASS_H__
#define __BASE_CLASS_H__
#include <iostream>
#include <string>
using namespace std;
//实现基类
class BaseClass {
public:
	//引用成员变量需要放在初始化列表中
	BaseClass():m_rnum(0){
		m_nAge = 88;
		cout << "call null param BaseClass constructor" << endl;
	}
	BaseClass(int nbase, int rnum, string name) :m_rnum(rnum), m_nbase(nbase), m_strName(name) {
		m_nAge = 88;
		cout << "call param BaseClass constructor" << endl;
	};
	//加上virtural关键字，当调用delete基类指针时会自动调用子类析构函数
	virtual ~BaseClass() { cout << "call BaseClass distructor~ " << endl; }
	static int  m_snum;
	int m_nAge;
	virtual void PrintClassData();
	void Overloadf();
	virtual void NetWork();
	void GreetClient(std::string str);
	void BaseExec();
	//C++ 11新特性，如果一个虚函数后面增加final修饰，则其子类无法重写该函数。
	//这么做的好处就是保证基类实现不会被重写，
	//也不会因为子类实现该函数时参数写错造成同名的基类函数隐藏。
	virtual void BaseC11()  final; 

	virtual void OverrideC11() ;
private:
	int m_nbase;
	string m_strName;
	//类的常引用成员变量
	const int & m_rnum;
};

class DeriveClass: public BaseClass{
public:
	DeriveClass() { m_nderive = 0; 
	cout << "call null param DeriveClass constructor" << endl;
	};
	DeriveClass(int nderive, int nbase, int rnum, string name) :m_nderive(nderive), BaseClass(nbase, rnum, name) {
		cout << "call param DeriveClass constructor" << endl;
	};
	~DeriveClass() {
		cout << "call DeriveClass distructor~" << endl;
	}
	//重写
	virtual void PrintClassData();
	//重定义Overload,基类该函数被隐藏。
	void Overloadf();
	//虽然声明了虚函数，但是和基类NetWork参数不同，无法形成虚函数重写，所以此处实际是重定义，隐藏基类的NetWork函数
	virtual void NetWork(int m);
	//普通函数,但是和基类GreetClient同名，所以隐藏基类函数GreetClient。
	void GreetClient(int id);
	//子类实现函数调用基类隐藏的函数GreetClient(str)
	void CallBaseGreetClient(string  str);
	//无法重写BaseC11，基类中声明此函数为final
	//virtual void BaseC11();

	//C++ 11新特性， override修饰的虚函数，必须要重写基类虚函数，并且编译器自动检测参数和类型
	virtual void OverrideC11() override;
public:
	int m_nscore;
private:
	int m_nderive;
};

#endif   // __BASE_CLASS_H__

