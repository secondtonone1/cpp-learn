// 03-pointer.cpp : 定义控制台应用程序的入口点。
//
#ifndef __TEMPLATEDEMO_H__
#define __TEMPLATEDEMO_H__
#include<iostream>
#include <vector>
#include <string>
using namespace std;
//定义函数模板，然后重载
template<typename T>
void swaptemp(T& t1, T& t2) {
	T temp = t1;
	t1 = t2;
	t2 = temp;
}

template<typename T>
void swaptemp(T* t1, T* t2) {
	T temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}

class StudentData {
public:
	StudentData(string name, int score) :m_strname(name), m_nscore(score) {}
	StudentData():m_strname(""),m_nscore(0){}
	string m_strname;
	int m_nscore;

};
//特例化
template<> void swaptemp<StudentData>(StudentData& s1, StudentData& s2) {
	int temp = s1.m_nscore;
	s1.m_nscore = s2.m_nscore;
	s2.m_nscore = temp;
}
#endif //__TEMPLATEDEMO_H__
