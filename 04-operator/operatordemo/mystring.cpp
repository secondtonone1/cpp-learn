// operatordemo.cpp : 定义控制台应用程序的入口点。
//

#include "mystring.h"

MyString::MyString() {
	m_chars = NULL;
	m_nlen = 0;
}

MyString::MyString(char * chars, int nlen) {
	m_chars = new char [nlen + 1];
	for (int i = 0; i < nlen; i++) {
		m_chars[i] = chars[i];
	}
	m_chars[nlen] = '\0';
	m_nlen = nlen + 1;
}

MyString::MyString(const MyString& mystring) {
	//防止自引用
	if (this == &mystring) {
		return;
	}
	m_nlen = mystring.m_nlen;
	m_chars = new char[m_nlen];
	for (int i = 0; i < m_nlen; i++) {
		m_chars[i] = mystring.m_chars[i];
	}
	m_chars[mystring.m_nlen - 1] = '\0';
	
}

MyString::~MyString() {
	if (m_chars != NULL) {
		delete[] m_chars;
		m_chars = NULL;
		m_nlen = 0;
	}
}

ostream & operator << (ostream& os, MyString mystring) {
	os << "chars are " << mystring.m_chars << endl;
	os << "chars len is " << mystring.m_nlen - 1 << endl;
	return os;
}

MyString MyString:: operator +(const MyString & mystring) const {
	int newlen = this->m_nlen - 1 + mystring.m_nlen;
	char * newchars = new char[newlen];
	for (int i = 0; i < this->m_nlen - 1; i++) {
		newchars[i] = this->m_chars[i];
	}
	for (int i = 0; i < mystring.m_nlen; i++) {
		newchars[i + this->m_nlen - 1] = mystring.m_chars[i];
	}
	MyString newstring(newchars, newlen-1);
	delete[] newchars;
	return newstring;
}