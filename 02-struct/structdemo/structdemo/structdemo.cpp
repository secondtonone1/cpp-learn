// structdemo.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
struct Student{
	char m_name[10];
	int age;
	int score;
	short sex;
};

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << sizeof(int) <<" "<< sizeof(short)<<std::endl;
	Student s1={"zack",31,100,0};
	std::cout << "s1 size is "<<sizeof(s1)<<std::endl;
	cout << &s1 <<endl;
	cout <<&s1.m_name<<endl;
	cout << & s1.age << endl;
	cout << &s1.score <<endl;
	cout <<&s1.sex <<endl;
	//�ṹ�����Ͳ����׼
	//����������������ʹ���4�ֽڣ�����4�ֽڼ�����룬������ʵ�����ʹ�С����
	//������ݴ�ŵ�λ�ò��������С������������Ҫ�ƶ�n���ֽڣ�ʹ�ó�Ա��ʼλ��
	//Ϊ�����ֽڴ�С��������
	//����ṹ�������С��������Ա�����ֽ�(����4�ֽڰ���4�ֽ�)������������������������
	// m_name 10�ֽ� + ����2�ֽ� + age���ֽ� + score���ֽ� + sex�����ֽ� = 22�ֽ�
	// 22 ����4�ı���������2�ֽڣ���Ϊ24
	system("pause");
	return 0;
}

