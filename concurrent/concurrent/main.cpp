// concurrent.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include "threademo.hpp"
#include "safestack.hpp"
#include "safequeue.hpp"
using namespace std;

int main()
{
	//use_thread();
	//unsafe_detach();
	//safe_guard();
	//param_thread();
	//update_thread();
	//bind_param();
	//use_scopethread();
	//test_safestack();
	test_safequeue();

	getchar();
    return 0;
}

