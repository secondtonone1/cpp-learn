
#include <iostream>
#include <string>
#include "vectorarray.h"
#include "funcdef.h"
using namespace std;
struct Student {
	string name;
	int age;
};
static void HelloFunc() {
	cout << "Hello world" << endl;
}
extern int sgnum2;
int main()
{
	//����һ��int���Ϳռ�
	int* p1 = new int(5);
	cout << *p1 << endl;
	if (p1 != NULL) {
		delete p1;
		p1 = NULL;
	}
	//����int����Ŀռ�
	int * p2 = new int[7];
	int * p2bak = p2;
	*p2 = 5;
	cout << *p2 << endl;
	*(p2 + 1) = 6;
	p2++;
	cout << *p2 << endl;
	//��++���ȼ�����*
	*p2++ = 7;
	cout << *(p2 - 1) << endl;
	//ǰ++���ȼ���*һ��������ǰ++����˳����ҵ���
	*++p2 = 8;
	cout << *p2 << endl;
	//����int����ռ�
	//ע�����ﲻ��delete []p2 ��Ϊp2ָ���Ѿ�����
	//��������ͨ��p2bak������p2����ĵ�ַ�����Ի���p2bak���ɡ�
	if (p2bak != NULL) {
		delete[] p2bak;
		p2bak = NULL;
	}

	//copy �ַ���
	char msg[] = "hello world";
	char * msg2 = new char[strlen(msg) + 1];
	strcpy_s(msg2, strlen(msg) + 1, msg);
	cout << msg2 << endl;

	auto s1 = new Student;
	s1->name = "LiLei";
	s1->age = 200;
	//C++ ����洢����������ջ��������Σ�ȫ������������
	//ȫ�����ַ�ΪBSS������������δ��ʼ����static����BSS��
	//��ʼ����static�������ݶ�
	char * schar1 = "constant segment";
	//schar1�洢��ջ�����ַ���constant segment �洢�ڳ��������ܱ��޸�
	static int sn1 = 1; //sn1�洢��������
	static int sn2; //sn2�洢��BSS��
	//extern ���������ڱ���ļ���������ȫ�ֱ���
	// ͬ��extern�����ı�����ʼ���˾�����������������BSS�� 
	//����δ�Ŷ����ƴ���Ϳ�ִ���ļ�
	//HelloFunc ���ڴ���Σ�ȫ�ֺ������ڴ����
	vecarrfunc();
	//�޷���main.cpp�е���vectorarray.h������staticȫ�ֺ�����
	//vecarrfunc2();
	
	cout << gnum << endl;
	cout << &gnum << endl;
	//��vectorarrary.cpp�����ɵ�sgnum����һ������
	cout << sgnum << " " << &sgnum << endl;
	int numarray[] = { 6,1,0,5,2,9 };
	selectsort(numarray, sizeof(numarray) / sizeof(int));
	getchar();
	return 0;
}

