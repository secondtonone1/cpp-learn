#ifndef __TEMPCLASS_H__
#define __TEMPCLASS_H__
#include <iostream>
#include <string>
using namespace std;
//类模板不是真正的类，只是告诉编译器如何生成类
//只有在类模板实例化后才会生成真正的类
//而cpp是单独编译的，将类模板放在cpp里实现会出现编译错误
template <typename T>
class TempClass {
public:
	TempClass(const T & t) {
		m_tData = t;
	}
	T& GetData() {
		return m_tData;
	}
	void SetData(const T& t);
private:
	T m_tData;
	//一般类的static成员变量需要放在cpp中初始化
	//类模板的static成员变量放在头文件中初始化
	static T m_tStatic;
};

//在头文件中初始化模板类的static成员
template<typename T>
T TempClass<T>::m_tStatic = 1024;

template<typename T>
void TempClass<T>::SetData(const T& t) {
	m_tData = t;
}

//explicit instanition 显式初始化, 声明TempClass类
//显示初始化在编译阶段就可以生成类对象，效率更好
template class TempClass<int> ;

//类模板也支持非类型参数，非类型参数只能是int，指针和引用类型

template <typename T,  int size>
class TempString {
public:
	TempString() {
		m_pchars = new T[size];
	}
	~TempString() {
		if (m_pchars != nullptr) {
			delete[] m_pchars;
		}
		m_pchars = nullptr;
	}

	void GetInfo() {
		cout << "size is " << size << endl;
	}
private:
	T * m_pchars;
};

//默认模板类型
template <typename T1,  typename T2 = int>
class DefaultClass {
public:
	DefaultClass(const T2& size) {
		m_data = new T1[size];
	}

	~DefaultClass() {
		if (m_data != nullptr) {
			delete[] m_data;
		}
		m_data = nullptr;
	}
private:
	T1 * m_data;
};

//模板偏特化和全特化(具体化)
//普通模板
template<typename T1, typename T2>
class NormalTemp {
public:
	NormalTemp(const T1 & t1, const T2 & t2) {
		cout << "This is normal template" << endl;
		m_t1data = t1;
		m_t2data = t2;
	}

	~NormalTemp() {
		
	}

	void PrintData() {
		cout << "This is normal template" << endl;
		cout << "t1data is " << m_t1data << endl;
		cout << "t2data is " << m_t2data << endl;
	}

private:
	T1 m_t1data;
	T2 m_t2data;
};

//偏特化模板
template <typename T1>
class NormalTemp<T1, char *> {
public:
	NormalTemp(const T1& t1, char * t2) {
		cout << "This is partitial template" << endl;
		m_t1data = t1;
		m_t2data = t2;
	}

	~NormalTemp() {

	}

	void PrintData() {
		cout << "This is patitial template" << endl;
		cout << "t1data is " << m_t1data << endl;
		cout << "t2data is " << m_t2data << endl;
	}

private:
	T1 m_t1data;
	char * m_t2data;
};

//全特化模板，也叫做具体化
template <>
class NormalTemp<int, char *> {
public:
	NormalTemp(const int& t1, char * t2) {
		cout << "This is full template" << endl;
		m_t1data = t1;
		m_t2data = t2;
	}

	~NormalTemp() {

	}

	void PrintData() {
		cout << "This is full template" << endl;
		cout << "t1data is " << m_t1data << endl;
		cout << "t2data is " << m_t2data << endl;
	}

private:
	int  m_t1data;
	char * m_t2data;
};


#endif //__TEMPCLASS_H__
