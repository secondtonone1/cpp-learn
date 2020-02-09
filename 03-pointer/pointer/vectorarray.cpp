// 03-pointer.cpp : 定义控制台应用程序的入口点。
//
#include "vectorarray.h"
#include <array>
#define ARRAY_SIZE 5
//在这里定义
int gnum = 6;
static int sgnum2 = 99;
void vecarrfunc() {
	//从vector尾部push数据
	vector<int> vec_n;
	vec_n.push_back(100);
	vec_n.push_back(200);
	//vector中数据为100，200
	for (unsigned int i = 0; i < vec_n.size() - 1; i++) {
		cout << vec_n[i] << endl;
	}
	//vector的size，即包含的元素个数
	cout << vec_n.size() << endl;
	//vector的capacity，容量。
	cout << vec_n.capacity() << endl;
	while (vec_n.size()) {
		cout << vec_n.back() << endl;
		vec_n.pop_back();
	}
	
	gnum++;
	cout << gnum << endl;
	cout << &gnum << endl;
	
	//调用static 全局函数vecarrfunc2
	vecarrfunc2();
}

void vecarrfunc2() {
	//初始化指定大小的vector
	vector<int> vec(10);
	vec.push_back(1024);
	vec.push_back(222);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << endl;
	}

	cout << gnum << endl;
	//vectorarray.cpp中生成sgnum实例，和main函数的sgnum是两个不同的变量
	//所以为了避免造成使用错误，static全局变量和普通的全局变量都要放在cpp中定义。
	sgnum++;
	cout << sgnum << " " << &sgnum << endl;
	//这里打印在cpp中定义的全局变量
	cout << sgnum2 << " " << &sgnum2 << endl;

	//C11 新增数组
	std::array<int, ARRAY_SIZE>  array_n = { 2, 5, 99, 1024 };
	//array支持迭代器遍历
	for (auto iter = array_n.begin(); iter != array_n.end(); iter++) {
		cout << *iter << endl;
	}
}