// cindemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include <string>
#include <sstream>
#include <istream>
using namespace std;
int main()
{
	cout << "please input a number " << endl;
	int number = 0;
	cin >> number;
	cout << "your input number is " << number << endl;
	string tempstr = "";
	int tempint = 0;
	cout << "Please input a number " << endl;
	cin >> tempstr;
	stringstream temstream;
	temstream.clear();
	temstream.str("");
	temstream << tempstr;
	temstream >> tempint;
	cout << tempint<<endl;
	//��������
	short nshort = 0;
	long long lshort = 1;
	double nd = 3.14;
	float nf = 3.33;
	//��������
	int cards[4] = { 3,4,5,7 };
    //�ñ������Զ�ͳ���������
	int cals[] = { 1,3,5,7 };
	int caln = sizeof(cals) / sizeof(int);
	cout << caln << endl;
	//C11 ����д��
	double darray[4]{ 1.24, 2.5,1.1,100.0 };
	cout << darray << endl;
	//�ַ���
	char carray[20] = "helloworld";
	//�ñ������Զ�ͳ�Ƹ���
	char coarray[] = "hello world!";
	cout << "Please enter your name" << endl;
	cin.clear();
	cin.ignore();
	char name[20];
	cin.getline(name, 20);
	cout << "your name is " << name << endl;
	//C11 ����ַ���
	char msg[] = "hello world";
	char msg2[] { "hello world2" };
	char msg3[] = { "hello world3" };
	cout << msg << endl;
	cout << msg2 << endl;
	cout << msg3 << endl;
	string msg4 = { "hello world4" };
	string msg5 { "hello world5" };

	system("pause");
	return 0;
}

