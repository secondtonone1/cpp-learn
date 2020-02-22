#ifndef __TEMPCLASS_H__
#define __TEMPCLASS_H__
#include <iostream>
#include <string>
using namespace std;
//��ģ�岻���������ֻ࣬�Ǹ��߱��������������
//ֻ������ģ��ʵ������Ż�������������
//��cpp�ǵ�������ģ�����ģ�����cpp��ʵ�ֻ���ֱ������
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
	//һ�����static��Ա������Ҫ����cpp�г�ʼ��
	//��ģ���static��Ա��������ͷ�ļ��г�ʼ��
	static T m_tStatic;
};

//��ͷ�ļ��г�ʼ��ģ�����static��Ա
template<typename T>
T TempClass<T>::m_tStatic = 1024;

template<typename T>
void TempClass<T>::SetData(const T& t) {
	m_tData = t;
}

//explicit instanition ��ʽ��ʼ��, ����TempClass��
//��ʾ��ʼ���ڱ���׶ξͿ������������Ч�ʸ���
template class TempClass<int> ;

//��ģ��Ҳ֧�ַ����Ͳ����������Ͳ���ֻ����int��ָ�����������

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

//Ĭ��ģ������
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

//ģ��ƫ�ػ���ȫ�ػ�(���廯)
//��ͨģ��
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

//ƫ�ػ�ģ��
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

//ȫ�ػ�ģ�壬Ҳ�������廯
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
