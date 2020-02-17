#ifndef __BASE_CLASS_H__
#define __BASE_CLASS_H__
#include <iostream>
#include <string>
using namespace std;
//ʵ�ֻ���
class BaseClass {
public:
	//���ó�Ա������Ҫ���ڳ�ʼ���б���
	BaseClass():m_rnum(0){
		m_nAge = 88;
		cout << "call null param BaseClass constructor" << endl;
	}
	BaseClass(int nbase, int rnum, string name) :m_rnum(rnum), m_nbase(nbase), m_strName(name) {
		m_nAge = 88;
		cout << "call param BaseClass constructor" << endl;
	};
	//����virtural�ؼ��֣�������delete����ָ��ʱ���Զ�����������������
	virtual ~BaseClass() { cout << "call BaseClass distructor~ " << endl; }
	static int  m_snum;
	int m_nAge;
	virtual void PrintClassData();
	void Overloadf();
	virtual void NetWork();
	void GreetClient(std::string str);
	void BaseExec();
	//C++ 11�����ԣ����һ���麯����������final���Σ����������޷���д�ú�����
	//��ô���ĺô����Ǳ�֤����ʵ�ֲ��ᱻ��д��
	//Ҳ������Ϊ����ʵ�ָú���ʱ����д�����ͬ���Ļ��ຯ�����ء�
	virtual void BaseC11()  final; 

	virtual void OverrideC11() ;
private:
	int m_nbase;
	string m_strName;
	//��ĳ����ó�Ա����
	const int & m_rnum;
};

class DeriveClass: public BaseClass{
public:
	DeriveClass() { m_nderive = 0; 
	cout << "call null param DeriveClass constructor" << endl;
	};
	DeriveClass(int nderive, int nbase, int rnum, string name) :m_nderive(nderive), BaseClass(nbase, rnum, name) {
		cout << "call param DeriveClass constructor" << endl;
	};
	~DeriveClass() {
		cout << "call DeriveClass distructor~" << endl;
	}
	//��д
	virtual void PrintClassData();
	//�ض���Overload,����ú��������ء�
	void Overloadf();
	//��Ȼ�������麯�������Ǻͻ���NetWork������ͬ���޷��γ��麯����д�����Դ˴�ʵ�����ض��壬���ػ����NetWork����
	virtual void NetWork(int m);
	//��ͨ����,���Ǻͻ���GreetClientͬ�����������ػ��ຯ��GreetClient��
	void GreetClient(int id);
	//����ʵ�ֺ������û������صĺ���GreetClient(str)
	void CallBaseGreetClient(string  str);
	//�޷���дBaseC11�������������˺���Ϊfinal
	//virtual void BaseC11();

	//C++ 11�����ԣ� override���ε��麯��������Ҫ��д�����麯�������ұ������Զ�������������
	virtual void OverrideC11() override;
public:
	int m_nscore;
private:
	int m_nderive;
};

#endif   // __BASE_CLASS_H__

