// stringdomo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	std::string name, job;
	cout << "Please input your name" <<endl;
	cin >> name;
	cout << "Please input your job" <<endl;
	cin >> job;
	cout << "your name is "<<name << " your job is "<< job <<endl;
	//16λ
	short i = 100;
	cout << "sizeof(short )" << sizeof(i) << endl;
	//32λ
	int j = 120;
	cout << "sizeof(int)" <<sizeof(j) <<endl;
	//32λ
	long k = 130;
	cout << "sizeof(long)" <<sizeof(k) <<endl;
	
	//����stringstreamƴ���ַ���
	stringstream strstreams;
	strstreams << "hello ";
	strstreams << "world ";
	cout << "string conncet is :"<<strstreams.str() <<endl;
	//���stringstream
	strstreams.str("");
	cout << "after clear is : "<<strstreams.str() <<endl;

	string istr= "";
	//����stringstreamת������
	stringstream convstream;
	convstream << i ;
	convstream >> istr;
	cout << "istr is " <<istr<<endl;
	//���ת��Ҫע�����stream
	convstream.str("");
	convstream.clear();
	convstream << 3.1415;
	convstream >> istr;
	cout << "istr is " <<istr<<endl;

	//c11ת��
	string convstr = to_string(95.27);
	cout << "conv string is : " << convstr <<endl;
	float fnum = stof(convstr);
	//���ƵĻ���stoi
	cout << "fnum is : " << fnum <<endl;
	//û��'\0'��char���鲻��string, cout�����������
	char msg[5]={'a','b','c','d','e'};
	//��'\0'���ַ������ͬ���ַ���
	char msg2[5]={'a','b','c','d','\0'};
	cout << "msg is : "<<msg2<< endl;
	//����û��'\0'��strlen����ĳ����Ǵ����
	//cout << strlen(msg) <<endl;
	//strlen���ҵ�\0�Ž���
	cout << "msg len is " << strlen(msg2) <<endl;

	//c98�ַ�����ʼ��
	auto str1 = "hello world!!!";
	char str2[20] = "hello world2!";
	//c11 �ַ�����ʼ��
	char str3[] = {"hello world3"};
	cout << str1 <<endl;
	cout << str2 << endl;
	cout << str3 <<" "<< strlen(str3) << endl;
	//��ֵ��ƴ��
	convstr = convstr+"zack";
	cout << convstr <<endl;
	//C���ƴ��������copy����
	char charray[15]={};
	strcpy_s(charray, str2);
	char charray2[40]={};
	cout << charray <<endl;
	strcat_s(charray2, charray);
	cout << charray2 <<endl;
	cout << sizeof(str3) <<endl;
	cout << sizeof(str2) <<endl;
	cout << convstr.length() <<endl;
	system("pause");
	return 0;
}

