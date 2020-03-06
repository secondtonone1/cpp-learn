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
	//copy���캯��
	Home(const Home& chome) {
		cout << "const copy constructor" << endl;
		m_strname = chome.m_strname;
		if (m_pKey != nullptr) {
			delete m_pKey;
		}
		//�����¿ռ䣬������copy����
		m_pKey = new int(*chome.m_pKey);
		cout << "m_pkey is " << m_pKey << endl;
		m_strname = chome.m_strname;
	}
	//��ֵmove���캯��
	Home(Home && rhome) {
		cout << "move constructor " << endl;
		if (m_pKey != nullptr) {
			delete m_pKey;
		}
		//��rhome�����ݸ�ֵ����ǰ����
		m_strname = rhome.m_strname;
		//�����ǵ�ֱַ�Ӹ�ֵ������ԭ���ݵĵ�ַ�ÿ�
		m_pKey = rhome.m_pKey;
		rhome.m_strname = "";
		//��ַ�ÿգ���ֹ����ʱ���deleteͬһ���ڴ�
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
		//�����ڴ棬�����ݸ�ֵ����
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
		//����ַ��ֵ�������������µĵ�ַ
		m_pKey = chome.m_pKey;
		//Ҫ��ԭ����ַ�ÿգ��������������������������deleteͬһ���ڴ�
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


