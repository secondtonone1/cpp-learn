// operatordemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include <string>
#include "mystring.h"
using namespace std;

int main()
{
	MyString mystring("hello world !", strlen("hello world !"));
	cout << mystring << endl;

	MyString mystring2(mystring);
	cout << mystring2 << endl;

	cout << mystring + mystring2 << endl;
	getchar();
    return 0;
}

