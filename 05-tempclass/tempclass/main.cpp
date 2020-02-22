#include "tempclass.h"
#include <iostream>
#include <string>
#include "starvesingle.h"
#include "lazysingle.h"
#include "templazy.h"
#include "lazyderive.h"
using namespace std;
int main()
{
	//implicit instanition ��ʽ��ʼ��
	TempClass<int> tmpc1(2048);
	cout << tmpc1.GetData() << endl;
	tmpc1.SetData(52);

	TempClass<int> tmpc2(222);
	cout << tmpc2.GetData() << endl;

	auto tmpstr = TempString<char, 20>();
	tmpstr.GetInfo();
	//ģ��Ĭ������T2 = int
	auto dfclass = DefaultClass<char>(100);

	//ģ��ĵ��ð���ʵ�̶ֳ���ߵĵ���,���þ��廯ģ��
	NormalTemp<int, char *>  nt1 (1024, "Hello World!!");
	nt1.PrintData();

	//����ƫ�ػ�ģ��
	NormalTemp<double, char *> nt2(1.34, "paritial");
	nt2.PrintData();

	//��ͨģ��
	NormalTemp<double, string> nt3(1.78, "normal temp");
	nt3.PrintData();

	//��������ģʽ����
	auto s1 = StarveSingle::GetInstance();
	auto s2 = StarveSingle::GetInstance();
	cout << s1 << endl;
	cout << s2 << endl;

	//��������ģʽ����
	auto lz1 = LazySingle::GetInstance();
	auto lz2 = LazySingle::GetInstance();
	cout << lz1 << " " << lz2 << endl;
	//��Ҫ�ֶ�������������������Դ
	if (lz1 != nullptr) {
		delete lz1;
		lz1 = nullptr;
	}
	cout << lz1 << " " << lz2 << endl;
	//��ε��û���ɱ���
  	//delete lz2;
	auto la1 = LazyAuto::GetInstance();
	auto la2 = LazyAuto::GetInstance();
	cout << la1 << " " << la2 << endl;
	//����Ҫ�ֶ��ͷţ�����ָ���Լ��ͷ�

	auto autop1 = LazySafeAuto::GetInstance();
	auto autop2 = LazySafeAuto::GetInstance();
	cout << autop1 << " " << autop2 << endl;

	//��������ʵ�ֵĵ���ģ�壬��������int
	auto tmplazy1 = TempLazy<int>::GetInstance();
	auto tmplazy2 = TempLazy<int>::GetInstance();
	cout << tmplazy1 << " " << tmplazy2 << endl;

	//�������ͼ̳�ģ�����ͣ�Ȼ��رչ��еĹ��캯��
	auto tmpd1 = LazyDerive::GetInstance();
	auto tmpd2 = LazyDerive::GetInstance();
	cout << tmpd1 << " " << tmpd2 << endl;
	getchar();
    return 0;
}

