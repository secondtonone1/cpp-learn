#include "lambdademo.h"
#include <utility>
#include <vector>
#include <algorithm>
void use_lambda() {
	std::vector<int> numbers = { 12,14,25,27,30,3,2 };
	std::count_if(numbers.begin(), numbers.end(), [](int a) {
		return a % 3 == 0;
	});
	int nouter = 3;
	//lambda���Բ�����������ֵ, ����ֱ�Ӵ��ݲ������ã����Ǻ��������޷��ް�nouter��ֵ����Ϊnouter������Ϊ��ֵ��
	int res = [nouter](int m)->int { return  nouter + m; }(1024);
	cout << "res is " << res << endl;
	//lambda�ɲ����ⲿ���������ã������ں����ڲ��޸�nouter���õ���ֵ���Ӷ��ﵽ�޸�nouter��Ŀ�ġ�
	res = [&nouter](int m)->int {nouter = m;  return nouter + m; }(1024);
	cout << "nouter is " << nouter << endl;
	cout << "res is " << res << endl;
	int nother = 5;
	string strname = "zack";
	//lambda����ͨ��=�������еı���ֵ
	//=��������������ֵ��&strname����strname������
	res = [=, &strname](string name) {
		strname = name + " " + strname;
		return nouter + nother;
	}("hello world");
	cout << "strname is " << strname << endl;
	cout << "res is " << res << endl;

	//&�����������б���������, strname����ֵ
	auto strres = [&, strname](string name) {nouter = 1; nother = 7;  return  strname + " " + name; }("hello world ");
	cout << "nouter is " << nouter << endl;
	cout << "strres is " << strres << endl;
	cout << "nother is " << nother << endl;
}

//lambda����ֲ�������Ҫ���Ǿֲ��������������ڣ�
//����ֲ��������ͷţ���lambda���������û��������
void push_func(LambQueue & funque) {
	//�ֲ�������push_func����������ñ����ͷ�
	int temp1 = 1;
	int temp2 = 3;
	cout << &temp1 << " " << &temp2 << endl;
	//lamfun����ֲ����������ǲ��Բ���ı�����������
	//����temp1��temp2������lamfun���������
	auto lamfun = [&](int a, int b) {
		cout << &temp1 << " " << &temp2 << endl;
		cout << a << " " << b << " " << temp1 << " " << temp2 << " " << endl;
		return a + b + temp1 + temp2;
	};
	//temp1�� temp2��������lambda�������������
	//temp1, temp2������push_func���е�}���ͷ�
	funque.push_back(lamfun);
}

void test_lambdalife() {
	LambQueue funque;
	push_func(funque);
	//push_func���ý������ڲ��ľֲ������ͷ���
	lambfunc lf;
	bool bres = funque.pop_front(lf);
	//���Դ�ʱpop_front���صĺ����������push_func�ڲ��ı�������Ϊ�ֲ������Ѿ����ͷţ����������
	if (bres) {
		auto data = lf(5, 7);
		cout << data << endl;
	}
}