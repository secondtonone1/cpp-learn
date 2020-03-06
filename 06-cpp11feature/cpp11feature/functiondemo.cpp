#include "functiondemo.h"
#include <utility>
#include <vector>
#include <algorithm>

int add(int a, int b) {
	return  a + b;
}

void use_funclass() {
	//���庯������
	FunctionClass funclass;
	//����operator()�������ˣ������������Ե�������ʹ��
	int res = funclass(5, 6);
	cout << res << endl;
	//����ָ�����Ͷ��庯��ָ��
	functype funcp = add;
	res = funcp(100, 200);
	cout << res << endl;
	//���Ƕ���һ������ָ��
	int(*funcp2)(int, int) = add;
	res = funcp2(300, 400);
	cout << res << endl;

	//typedef ������һ�����ͣ���typedef unsigned int  uint ���Ƕ�����һ���µ�����
	//��int  uint ���Ƕ�����һ������
	//ͬ���ĵ��� typedef int(*funcp)(int, int) ������funcpΪ����ָ������
	//int (*funcp)(int, int)�����˺���ָ�����

	functype2  funcp3 = add;
	res = funcp3(200, 200);
	cout << res << endl;

	functype3 funcp4 = add;
	res = funcp4(102, 102);
	cout << res << endl;
}

void use_function() {
	//����һ��function���󣬵���ȫ�ֺ���
	function<int(int, int)> funcob = add;
	int res = funcob(1024, 1024);
	cout << res << endl;
	FunctionClass classobj;
	//����function������ú�������
	function<int(int, int)> classob = classobj;
	res = classob(200, 300);
	cout << res << endl;
	//function�������lambda���ʽ
	function<bool(int)> compareob = [&res](int m) {
		return res > m;
	};
	bool bres = compareob(200);
	cout << bres << endl;
	//function�������ģ����
	function<int(int, int)> minusob = TempClass<int>();
	res = minusob(100, 50);
	cout << res << endl;
	//������ľ�̬��Ա����
	function<int(int, int)> mulob = FunctionClass::multi;
	res = mulob(3, 5);
	cout << res << endl;

	//������ĳ�Ա
	function<int(FunctionClass&)>f = &FunctionClass::m_num;
	FunctionClass funcobj2;
	cout << f(funcobj2) << endl;
	
	//����ĳ�Ա��������������Ϊvoid����

	FunctionDemo  funcdm;
	function<void ( int, int)> fpadd = std::bind(&FunctionDemo::print_add, funcdm, placeholders::_1, placeholders::_2);
	fpadd(3, 4);
	//��������Ϊ����������string���͵ĺ�������ʱ������auto��
	//����д��function<string(string, string)>�������
	auto fsstract = std::bind(&FunctionDemo::constract_str, & funcdm, placeholders::_1, placeholders::_2);
	fsstract("Hello", " World!");
	//����ľ�̬����
	function<int(int, int)> fstatic = std::bind(&FunctionClass::multi, placeholders::_1, placeholders::_2);
	fstatic(200, 90);
}
