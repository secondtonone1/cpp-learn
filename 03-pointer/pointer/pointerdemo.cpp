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

//dealmularray也可以将第一个参数修改如下，同样接受二维数组
// static void dealmularray(int (*pmularray)[4], int nsize);

inline void inlinefunc() {
	cout << "this is a inline func" << endl;
}

void pointer_demo() {
	//开辟一个int类型的指针
	int *pn = new int(5);
	cout << *pn << endl;
	//回收
	if (pn != NULL) {
		delete pn;
		pn = NULL;
	}
	//开辟一个int类型的数组指针
	int * pan = new int[5];
	*(pan + 1) = 100;
	//回收数组
	delete[]pan;

	//指向常量的指针
	int age = 99;
	const int * page = &age;
	//page是一个指针，指向的内容不可修改，不能通过指针修改指向的值。
	//*page = 100;
	//但是可以通过对原来的变量修改
	age = 1024;
	//常量指针，指针本身的值不能修改，但是指向的内容可以修改。
	int * const cpage = &age;
	//可以修改cpage指向的内容
	*cpage = 89;
	//不可以修改cpage的值
	//cpage++;
	//cpage = pan;

	//我们声明一个常量数组
	const int const_array[] = { 1,3,4,7 };
	//dealconstarray参数为const int * p可以接受常量数组
	dealconstarray(const_array, sizeof(const_array) / sizeof(int));
	//dealarrary为int *p 参数，不可接受常量数组
	//dealarray(const_array, sizeof(const_array) / sizeof(int));
	//不能将常量的地址赋值给指向非常量的指针
	const string name = "Zack";
	//string * pname = &name;
	//可以用指向常量的指针接受name地址
	const string * pname = &name;
	//如果函数内部不修改形参，尽量多使用const引用或指向常量的指针
	dealconstname(name);
	//定义一个函数指针
	void(*pfunc)(int *parray, int nlen);
	//pfunc指向dealarray函数
	pfunc = dealarray;
	int n_array[] = { 3,5,9,8,11 };
	//通过函数指针调用函数
	pfunc(n_array, 5);

	//利用typedef简化函数指针,定义函数指针类型
	typedef void(*pfuntype)(const int * parray, int nlen);
	//通过函数指针类型定义一个函数指针，指向dealconstarray
	pfuntype pfun2 = dealconstarray;
	pfun2(const_array, sizeof(const_array) / sizeof(int));

	//二维数组
	int a[3][4] = { {1,3,4,5}, {2,4,6,7}, {1,8,9,0} };
	dealmularray(a, 3);
	inlinefunc();
}

void reference_demo() {
	int age = 78;
	//rage是age的引用，定义的同时必须初始化
	int & rage = age;
	cout << "age address is: "<<  &age << " age is :  "<< age << endl;
	cout << "rage address is: " << &rage << " rage is :  " << rage << endl;
	//修改rage的值，但是rage一直都是age的引用，age的值也会被修改
	int newage = 92;
	//rage的值被修改为newage，但是rage是age的引用，无法被修改
	rage = newage;
	cout << "age address is: " << &age << " age is :  " << age << endl;
	cout << "rage address is: " << &rage << " rage is :  " << rage << endl;
	cout << "newage address is: " << &newage << " newage is :  " << newage << endl;
	//可以看出age和rage地址相同，即同一个变量。
}