#include "functionbind.h"
#include <utility>
#include <vector>
#include <algorithm>

void fun(int x, int y, int z)
{
	cout << x << "  " << y << "  " << z << endl;
}

void fun_2(int &a, int &b)
{
	a++;
	b++;
	cout << a << "  " << b << endl;
}

void use_funcmem() {
	//f1������Ϊ function<void(int, int, int)>
	auto f1 = std::bind(fun, 1, 2, 3); //��ʾ�󶨺��� fun �ĵ�һ��������������ֵΪ�� 1 2 3
	f1(); //print:1  2  3

	auto f2 = std::bind(fun, placeholders::_1, placeholders::_2, 3);
	//��ʾ�󶨺��� fun �ĵ���������Ϊ 3����fun �ĵ�һ�����������ֱ��ɵ��� f2 �ĵ�һ����������ָ��
	f2(1, 2);//print:1  2  3

	auto f3 = std::bind(fun, placeholders::_2, placeholders::_1, 3);
	//��ʾ�󶨺��� fun �ĵ���������Ϊ 3����fun �ĵ�һ�����������ֱ��ɵ��� f3 �ĵڶ���һ������ָ��
	//ע�⣺ f2  ��  f3 ������
	f3(1, 2);//print:2  1  3


	int n = 2;
	int m = 3;

	auto f4 = std::bind(fun_2, n, placeholders::_1); //��ʾ��fun_2�ĵ�һ������Ϊn, fun_2�ĵڶ��������ɵ���f4�ĵ�һ��������_1��ָ����
	f4(m); //print:3  4

	cout << m << endl;//print:4  ˵����bind���ڲ����Ȱ󶨵Ĳ�����ͨ��std::placeholders���ݵĲ�����ͨ�����ô��ݵ�,��m
	cout << n << endl;//print:2  ˵����bind����Ԥ�Ȱ󶨵ĺ���������ͨ��ֵ���ݵģ���n


	A a;
	//f5������Ϊ function<void(int, int)>
	auto f5 = std::bind(&A::fun_3, a, placeholders::_1, placeholders::_2); //ʹ��auto�ؼ���
	f5(10, 20);//����a.fun_3(10,20),print:10 20

	std::function<void(int, int)> fc = std::bind(&A::fun_3, a, std::placeholders::_1, std::placeholders::_2);
	fc(10, 20);//����a.fun_3(10,20) print:10 20 

	auto f6 = std::bind(&A::fun_4, a, std::placeholders::_1, std::placeholders::_2);
	f6("hello ", " world!");

}
