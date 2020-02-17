#ifndef __MY_STRING_H__
#define __MY_STRING_H__
#include <iostream>
#include <string>
using namespace std;
//实现一个string类，支持string基本功能
class MyString {
public:
	MyString();
	MyString(char * chars, int nlen);
	MyString(const char * chars);
	MyString(const MyString& mystring); 
	~MyString();
	friend  ostream & operator << (ostream& os  ,MyString mystring);
	friend bool operator < (const MyString & s1, const MyString & s2);
	friend bool operator == (const MyString & s1, const MyString & s2);
	friend bool operator > (const MyString & s1, const MyString & s2);
	MyString & operator = (const MyString& mystring);
	MyString  operator +(const MyString & mystring) const;
	char & operator [](unsigned int n);
	const char & operator [](unsigned int n) const;
	MyString & operator = (const char * msg);
	
private:
	char* m_chars;
	int m_nlen;
};
#endif

