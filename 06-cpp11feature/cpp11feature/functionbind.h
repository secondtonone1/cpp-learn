#ifndef  __FUNCTION_BIND_H__
#define __FUNCTION_BIND_H__
#include <string>
#include <iostream>
#include <list>
#include <functional>
using namespace std;
class A
{
public:
	A() = default;
	void fun_3(int k, int m)
	{
		cout << k << " " << m << endl;
	}
	string fun_4(string a, string b) {
		return a + b;
	}
};



extern void use_funcmem();

#endif // __FUNCTION_BIND_H__

