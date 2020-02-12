#include "pointerdemo.h"

static void dealarray(int *parray, int nlen) {
	for (int i = 0; i < nlen; i++) {
		cout << parray[i] << " ";
	}
	cout << endl;
}

static void dealconstarray(const int * parray, int nlen) {
	for (int i = 0; i < nlen; i++) {
		cout << parray[i] << " ";
	}
	cout << endl;
}

static void dealconstname(const string & name) {
}

static void dealmularray(int mularray[][4], int nsize) {
	for (int i = 0; i < nsize; i++) {
		for (int j = 0; j < 4; j++) {
			cout << mularray[i][j] << " ";
		}
		cout << endl;
	}
}

//dealmularrayҲ���Խ���һ�������޸����£�ͬ�����ܶ�ά����
// static void dealmularray(int (*pmularray)[4], int nsize);

inline void inlinefunc() {
	cout << "this is a inline func" << endl;
}

void pointer_demo() {
	//����һ��int���͵�ָ��
	int *pn = new int(5);
	cout << *pn << endl;
	//����
	if (pn != NULL) {
		delete pn;
		pn = NULL;
	}
	//����һ��int���͵�����ָ��
	int * pan = new int[5];
	*(pan + 1) = 100;
	//��������
	delete[]pan;

	//ָ������ָ��
	int age = 99;
	const int * page = &age;
	//page��һ��ָ�룬ָ������ݲ����޸ģ�����ͨ��ָ���޸�ָ���ֵ��
	//*page = 100;
	//���ǿ���ͨ����ԭ���ı����޸�
	age = 1024;
	//����ָ�룬ָ�뱾���ֵ�����޸ģ�����ָ������ݿ����޸ġ�
	int * const cpage = &age;
	//�����޸�cpageָ�������
	*cpage = 89;
	//�������޸�cpage��ֵ
	//cpage++;
	//cpage = pan;

	//��������һ����������
	const int const_array[] = { 1,3,4,7 };
	//dealconstarray����Ϊconst int * p���Խ��ܳ�������
	dealconstarray(const_array, sizeof(const_array) / sizeof(int));
	//dealarraryΪint *p ���������ɽ��ܳ�������
	//dealarray(const_array, sizeof(const_array) / sizeof(int));
	//���ܽ������ĵ�ַ��ֵ��ָ��ǳ�����ָ��
	const string name = "Zack";
	//string * pname = &name;
	//������ָ������ָ�����name��ַ
	const string * pname = &name;
	//��������ڲ����޸��βΣ�������ʹ��const���û�ָ������ָ��
	dealconstname(name);
	//����һ������ָ��
	void(*pfunc)(int *parray, int nlen);
	//pfuncָ��dealarray����
	pfunc = dealarray;
	int n_array[] = { 3,5,9,8,11 };
	//ͨ������ָ����ú���
	pfunc(n_array, 5);

	//����typedef�򻯺���ָ��,���庯��ָ������
	typedef void(*pfuntype)(const int * parray, int nlen);
	//ͨ������ָ�����Ͷ���һ������ָ�룬ָ��dealconstarray
	pfuntype pfun2 = dealconstarray;
	pfun2(const_array, sizeof(const_array) / sizeof(int));

	//��ά����
	int a[3][4] = { {1,3,4,5}, {2,4,6,7}, {1,8,9,0} };
	dealmularray(a, 3);
	inlinefunc();
}

void reference_demo() {
	int age = 78;
	//rage��age�����ã������ͬʱ�����ʼ��
	int & rage = age;
	cout << "age address is: "<<  &age << " age is :  "<< age << endl;
	cout << "rage address is: " << &rage << " rage is :  " << rage << endl;
	//�޸�rage��ֵ������rageһֱ����age�����ã�age��ֵҲ�ᱻ�޸�
	int newage = 92;
	//rage��ֵ���޸�Ϊnewage������rage��age�����ã��޷����޸�
	rage = newage;
	cout << "age address is: " << &age << " age is :  " << age << endl;
	cout << "rage address is: " << &rage << " rage is :  " << rage << endl;
	cout << "newage address is: " << &newage << " newage is :  " << newage << endl;
	//���Կ���age��rage��ַ��ͬ����ͬһ��������
}