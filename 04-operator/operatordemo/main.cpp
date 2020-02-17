// operatordemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include <string>
#include "mystring.h"
#include "baseclass.h"
#include "friendclass.h"
using namespace std;

int main()
{
	MyString mystring("hello world !", strlen("hello world !"));
	cout << mystring << endl;

	MyString mystring2(mystring);
	cout << mystring2 << endl;

	cout << mystring + mystring2 << endl;

	MyString mystring3("My name is zack!", strlen("My name is zack!"));
	cout << mystring3 << endl;
	mystring2 = mystring3;
	mystring3 = mystring;
	cout << "mystring2 is : "<<mystring2 << endl;
	cout << "mystring3 is : " << mystring3 << endl;
	if (mystring2 < mystring) {
		cout << "mystring is bigger" << endl;
	}
	else {
		cout << "mystring3 is bigger" << endl;
	}

	MyString mystring4 = "nothing seriouse";
	cout << mystring4 << endl;

	//��ʼ���������
	BaseClass bc = BaseClass(2, 1024, "BaseClass");
	//��ʼ���������
	DeriveClass dc = DeriveClass(105, 202, 403, "DeriveClass");
	//��������е�static����
	cout << BaseClass::m_snum << endl;
	//��������е�static����
	cout << DeriveClass::m_snum << endl;
	//���������ֵ����������
	BaseClass & rbc = DeriveClass(105, 202, 403, "DeriveClass");
	//�������͵����ã����Է��ʻ���ĳ�Ա
	cout << rbc.m_nAge << endl;
	//�����Է�������ĳ�Ա
	//rbc.m_nscore;
	//�������͵����ã���ʱ���õ���������󣬵����麯�����������ʵ�ֵĹ���
	rbc.PrintClassData();
	//�������͵����ñ���������ͨ�ĺ���,ʵ�ʵ��õ��ǻ��ຯ��
	rbc.Overloadf();
	//������������ͨ�ĺ��������õ�������ĺ�������Ϊ����ĺ����������ˡ�
	dc.Overloadf();

	//����ָ����ã���̬
	BaseClass *pBase = new DeriveClass(1024, 2048, 512, "hello world");
	pBase->PrintClassData();
	pBase->Overloadf();
	//����ת��
	DeriveClass* pDerive =  dynamic_cast<DeriveClass*>(pBase);
	pDerive->PrintClassData();
	pDerive->Overloadf();
	//�ܽ��£����������õ����ĸ����������ȿ�������ָ��(����)������ͨ����
	//1  �������ͨ�������۵����麯��������ͨ�����������õ�������ĺ�����
	//��Ȼ����û��ʵ�ָú���������õ��ǻ���ĺ�����
	// 2 �����ָ��������ã���������������ָ������ã���ô���õľ�������ĺ���
	//��Ȼ����ûʵ�ָú���������õ��ǻ��ຯ��������1һ����
	// 3 ���������ָ������ã�ָ����������ô�����麯���Ƕ�̬Ч����Ҳ����
	//���������ʵ�ֺ��������������ͨ���������ǻ����ʵ�ֺ�����
	
	//������ָ��һ������ͬ������������ͬ
	//����(��д)override, �����麯����������д�����������ֵ���͵ȶ���ͬ���������ʵ�ֻ����ͬ���麯����
	//���ǲ�����ͬ�������ɻ����麯�������أ������麯�����ǡ�
	//�ض������� redifine ָ����ʵ���˻����ͬ����������Ҫ��ʵ�ֵĺ����ͻ����β�������ͬ����ɻ��ຯ��������

	//�����޷����û���ʵ�ֵ�NetWork����Ϊ���ຯ����������
	//pDerive->NetWork();
	//������Ե����Լ�ʵ�ֵ�NetWork����
	pDerive->NetWork(126);
	//ͬ��������Ҳ�޷����û����GreetClient(str)����������ص�Ч����ֻ�ܵ����Լ���GreetClient(int)
	//pDerive->GreetClient("Hello World");
	pDerive->GreetClient(204);
	//������û������صĺ��������ַ�ʽ��1 ��̬ת��Ϊ�������� 2���߽���������ת��Ϊ������ú������ɡ�
	BaseClass* pBase2 = dynamic_cast<BaseClass*>(pDerive);
	pBase2->GreetClient("Hello QBYC");
	pBase2->NetWork();
	//ͨ�����ຯ���ڲ�ʵ��BaseClass::GreetClient����
	pDerive->CallBaseGreetClient("Hello tao");
	//�����ʱ��pDerive����ת��Ϊ����ָ��
	pBase = dynamic_cast<BaseClass*>(pDerive);
	//�����麯��PrintClassData������̬��
	pBase->PrintClassData();

	//ͨ������ָ��ָ��������󣬵���BaseExec
	//����OverloadΪ��ͨ������pBase���û����Overload,ָ����ʲô���;͵��ö�Ӧ��ʵ�ֺ������������麯����д���ɶ�̬
	//��PrintClassDataΪ�麯����pBase�ڲ����麯������д��PrintClassData������������PrintClassData
	pBase->BaseExec();
	//����һ���������
	DeriveClass drclass = DeriveClass();
	//����������BaseExec
	//�����������û��ʵ��BaseExec�����Ի���û����BaseExec
	//���û����BaseExecʱ��C++�Զ�������ʽת�� DeriveClassת��ΪBaseClass 
	//���Ե���Overload�����ͨ�ĳ�Ա����ʱ���ǿ�����ǵ���ʱ������ΪBaseClass����ʱ���õ�Ϊ�����Overload
	//����PrintClassData�����ǿ���ʵ������ΪDeriveClass��DeriveClass�麯������д�˸ú�������ʱ���õ��������PrintClassData
	drclass.BaseExec();
	//final �������õĶ��ǻ����
	pDerive->BaseC11();
	pBase->BaseC11();
	//���������麯��
	pBase->OverrideC11();
	//��������д���麯��������delete ����ָ�����ʵ���ȵ������������ٵ��û��������Ĺ���
	delete pBase;
	//�麯������ľ�̬��Ա����ľ�̬��Ա��������ռ�ÿռ�
	//һ�������Ĵ�С��ѭ����Ͳ���ԭ��
	//�������������麯�����������Ĵ�С������ֽ�ָ�룬ָ���麯�����麯�������麯������
	//����һ�����麯������������ڴ湹��Ϊ��ʼ�����ֽڴ洢�麯�����ַ�����������ֽ���ѭ
	//����Ͳ����ԭ�����������ؼ̳У�����ݻ����Ƿ����麯��������оͶ����������ֽڣ���Ϊ
	//��ͬ�Ļ����麯��Ҫ���ڲ�ͬ�ı�����Ծͻ��ж��ָ���麯�����ָ�룬�Ǿ��ж�����ֽڡ�
	//�����ĵ��Ͳ��Կ��Կ��ҵļ������� https://www.limerence2017.com/2017/08/03/cppvirtual/

	//��Ԫ����Է����������˽�г�Ա
	auto friendcl = FriendClass();
	auto privatecl = PrivateClass();
	friendcl.DealPrivateClass(privatecl);
	getchar();
    return 0;
}

