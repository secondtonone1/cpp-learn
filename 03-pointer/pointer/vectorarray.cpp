// 03-pointer.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "vectorarray.h"
#include <array>
#define ARRAY_SIZE 5
//�����ﶨ��
int gnum = 6;
static int sgnum2 = 99;
void vecarrfunc() {
	//��vectorβ��push����
	vector<int> vec_n;
	vec_n.push_back(100);
	vec_n.push_back(200);
	//vector������Ϊ100��200
	for (unsigned int i = 0; i < vec_n.size() - 1; i++) {
		cout << vec_n[i] << endl;
	}
	//vector��size����������Ԫ�ظ���
	cout << vec_n.size() << endl;
	//vector��capacity��������
	cout << vec_n.capacity() << endl;
	while (vec_n.size()) {
		cout << vec_n.back() << endl;
		vec_n.pop_back();
	}
	
	gnum++;
	cout << gnum << endl;
	cout << &gnum << endl;
	
	//����static ȫ�ֺ���vecarrfunc2
	vecarrfunc2();
}

void vecarrfunc2() {
	//��ʼ��ָ����С��vector
	vector<int> vec(10);
	vec.push_back(1024);
	vec.push_back(222);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << endl;
	}

	cout << gnum << endl;
	//vectorarray.cpp������sgnumʵ������main������sgnum��������ͬ�ı���
	//����Ϊ�˱������ʹ�ô���staticȫ�ֱ�������ͨ��ȫ�ֱ�����Ҫ����cpp�ж��塣
	sgnum++;
	cout << sgnum << " " << &sgnum << endl;
	//�����ӡ��cpp�ж����ȫ�ֱ���
	cout << sgnum2 << " " << &sgnum2 << endl;

	//C11 ��������
	std::array<int, ARRAY_SIZE>  array_n = { 2, 5, 99, 1024 };
	//array֧�ֵ���������
	for (auto iter = array_n.begin(); iter != array_n.end(); iter++) {
		cout << *iter << endl;
	}
}