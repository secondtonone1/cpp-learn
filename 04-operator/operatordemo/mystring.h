#ifndef __MY_STRING_H__
#define __MY_STRING_H__
#include <iostream>
#include <string>
using namespace std;
//ʵ��һ��string�֧࣬��string��������
class MyString {
public:
	MyString();
	MyString(char * chars, int nlen);
	MyString(const MyString& mystring); 
	~MyString();
	friend  ostream & operator << (ostream& os  ,MyString mystring);
	MyString  operator +(const MyString & mystring) const;
private:
	char* m_chars;
	int m_nlen;
};
#endif

