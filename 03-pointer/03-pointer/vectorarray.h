// 03-pointer.cpp : 定义控制台应用程序的入口点。
//
#ifndef __VECTORARRARY_H__
#define __VECTORARRARY_H__
#include<iostream>
#include <vector>
using namespace std;

void vecarrfunc() {
	vector<int> vec_n;
	vec_n.push_back(100);
	vec_n.push_back(200);
	for (unsigned int i = 0; i < vec_n.size() - 1; i++) {
		cout << vec_n[i] << endl;
	}
	cout << vec_n.capacity() << endl;
	while (vec_n.size()) {
		cout << vec_n.back() << endl;
		vec_n.pop_back();
	}
}
#endif //__VECTORARRARY_H__
