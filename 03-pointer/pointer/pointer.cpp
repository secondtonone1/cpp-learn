
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
	//开辟一个int类型空间
	int* p1 = new int(5);
	cout << *p1 << endl;
	if (p1 != NULL) {
		delete p1;
		p1 = NULL;
	}
	//开辟int数组的空间
	int * p2 = new int[7];
	int * p2bak = p2;
	*p2 = 5;
	cout << *p2 << endl;
	*(p2 + 1) = 6;
	p2++;
	cout << *p2 << endl;
	//后++优先级高于*
	*p2++ = 7;
	cout << *(p2 - 1) << endl;
	//前++优先级和*一样，但是前++运算顺序从右到左
	*++p2 = 8;
	cout << *p2 << endl;
	//回收int数组空间
	//注意这里不能delete []p2 因为p2指向已经变了
	//但是我们通过p2bak备份了p2最初的地址，所以回收p2bak即可。
	if (p2bak != NULL) {
		delete[] p2bak;
		p2bak = NULL;
	}

	//copy 字符串
	char msg[] = "hello world";
	char * msg2 = new char[strlen(msg) + 1];
	strcpy_s(msg2, strlen(msg) + 1, msg);
	cout << msg2 << endl;

	auto s1 = new Student;
	s1->name = "LiLei";
	s1->age = 200;
	//C++ 五个存储区，堆区，栈区，代码段，全局区，常量区
	//全局区又分为BSS区和数据区，未初始化的static放在BSS段
	//初始化的static放在数据段
	char * schar1 = "constant segment";
	//schar1存储在栈区，字符串constant segment 存储在常量区不能被修改
	static int sn1 = 1; //sn1存储在数据区
	static int sn2; //sn2存储在BSS段
	//extern 用来引用在别的文件中生命的全局变量
	// 同样extern生命的变量初始化了就在数据区，否则在BSS段 
	//代码段存放二进制代码和可执行文件
	//HelloFunc 放在代码段，全局函数放在代码段
	vecarrfunc();
	//无法在main.cpp中调用vectorarray.h声明的static全局函数。
	//vecarrfunc2();
	
	cout << gnum << endl;
	cout << &gnum << endl;
	//和vectorarrary.cpp中生成的sgnum不是一个变量
	cout << sgnum << " " << &sgnum << endl;
	int numarray[] = { 6,1,0,5,2,9 };
	selectsort(numarray, sizeof(numarray) / sizeof(int));
	getchar();
	return 0;
}

