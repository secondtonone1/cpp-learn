#ifndef  __MOVE_DEMO_H__
#define __MOVE_DEMO_H__
#include <string>
#include <iostream>
using namespace std;

class Home {
public:
	Home(string name,  int nkey):m_strname(name), m_pKey(new int (nkey)){
		cout << "param constructor " << endl;
		cout << "m_pkey is " << m_pKey << endl;
	}
	Home() :m_strname(""), m_pKey(nullptr) {
		cout << "default constructor " << endl;
	}
	~Home() {
		cout << "Home destructor" << endl;
		cout << "m_pKey is " << m_pKey << endl;
		if (m_pKey != nullptr) {
			cout << "destruct memory" << endl;
			delete m_pKey;
		}
		m_pKey = nullptr;
	}
	//copy构造函数
	Home(const Home& chome) {
		cout << "const copy constructor" << endl;
		m_strname = chome.m_strname;
		if (m_pKey != nullptr) {
			delete m_pKey;
		}
		//开辟新空间，将数据copy过来
		m_pKey = new int(*chome.m_pKey);
		cout << "m_pkey is " << m_pKey << endl;
		m_strname = chome.m_strname;
	}
	//右值move构造函数
	Home(Home && rhome) {
		cout << "move constructor " << endl;
		if (m_pKey != nullptr) {
			delete m_pKey;
		}
		//将rhome的数据赋值给当前对象
		m_strname = rhome.m_strname;
		//这里是地址直接赋值，并将原数据的地址置空
		m_pKey = rhome.m_pKey;
		rhome.m_strname = "";
		//地址置空，防止析构时多次delete同一块内存
		rhome.m_pKey = nullptr;
	}

	Home & operator = ( Home & chome) {
		cout << "copy assignment operator = " << endl;
		if (this == &chome) {
			return *this;
		}

		if (m_pKey != nullptr) {
			delete m_pKey;
		}
		m_strname = chome.m_strname;
		//开辟内存，将数据赋值过来
		m_pKey = new int(*chome.m_pKey);
		cout << "m_pkey is " << m_pKey << endl;
		return *this;
	}

	Home & operator = ( Home && chome) {
		cout << "copy operator = " << endl;
		if (this == &chome) {
			return *this;
		}

		if (m_pKey != nullptr) {
			delete m_pKey;
		}
		m_strname = chome.m_strname;
		//将地址赋值过来，不开辟新的地址
		m_pKey = chome.m_pKey;
		//要将原来地址置空，否则两个对象调用析构函数会delete同一块内存
		chome.m_pKey = nullptr;
		chome.m_strname = "";
		return *this;
	}

private:
	string m_strname;
	int * m_pKey;
};

extern void use_move();

#endif  __MOVE_DEMO_H__


