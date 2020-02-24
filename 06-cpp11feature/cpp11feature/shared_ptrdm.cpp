#include "shared_ptrdm.h"
#include <memory>
#include <iostream>
using namespace std;
void use_sharedptr() {
	//指向int类型的智能指针，shared_ptr可以随着赋值和引用，增加引用计数
	//自动调用析构函数，当引用计数为0，则回收资源
	shared_ptr<int>  sh_n = shared_ptr<int>(new int(5));
	//注意此处use_count为shared_ptr类的成员函数，所以用.
	cout << sh_n.use_count() << endl;
	//shared_ptr取类成员数据要用->
	shared_ptr<Student> student_p = shared_ptr<Student>(new Student("Zack", 25, 100));
	cout << student_p->GetName() << endl;
	//可以使用*解引用
	cout << *sh_n << endl;
	//shared_ptr支持赋值操作，引用计数增加1
	shared_ptr<int> sh_n2 = sh_n;
	//输出引用计数
	cout << sh_n.use_count() << endl;
	//shared_ptr 支持copy构造
	shared_ptr<int> sh_n3(sh_n);
	cout << sh_n3.use_count() << endl;
	//shared_ptr 的参数构造函数也支持原生指针
	shared_ptr<int> sh_n4(new int(8));
	//智能指针的初始引用次数为1
	cout << sh_n4.use_count() << endl;
	//智能指针另一种构造方式,（）里写构造函数的参数即可
	shared_ptr<int> sh_n5 = make_shared<int>(1024);
	//将智能指针还原为原生指针
	int * raw_p =sh_n5.get();
	cout << *raw_p << endl;
}
unique_ptr<Student>  return_unique() {
	unique_ptr<Student> us = unique_ptr<Student>(new Student("Temp", 20, 20));
	return us;
}
void use_uniqueptr() {
	//unique ptr 对于指针指向的资源是独占的，
	//通过赋值给别的指针，会解除当前unique_ptr对资源的占用
	unique_ptr<Student> us1 = unique_ptr<Student>(new Student("Zack", 26, 120));
	cout << us1->GetName() << endl;
	//不允许将一个unique_ptr对象赋值给另一个,除非这个unique_ptr是右值或者在当前作用域立刻释放
	// unique_ptr 的赋值操作已被删除
   //	unique_ptr<Student> us2 = us1;
	//但是可以通过临时变量(右值)初始化另一个unique_ptr
	unique_ptr<Student> us2 = unique_ptr<Student>(new Student("Rolin", 25, 229));
	cout << us2->GetName() << endl;
	//也可以通过一个函数返回unique_ptr赋值给另一个unique_ptr变量,因为局部的unique_ptr在函数结束会析构
	unique_ptr<Student> us3 = return_unique();
	cout << us3->GetName() << endl;
	//可以通过std::move 转移unique的所有权，这样被转移的unique无法继续使用
	unique_ptr<Student> us4 = std::move(us1);
	cout << us4->GetName() << endl;
	//所有权被转移，所以无法继续使用us1
	//cout << us1->GetName() << endl;
	//unique 可以通过release自动释放资源所有权
	us4.release();
	//us4也无法使用
	//us4->GetName();
}

//不使用智能指针，回收内存要注意避免多次回收
//也要注意避免少回收造成内存泄漏
void raw_ptr() {
	auto pteacher = new TeacherRaw("Herly", 30);
	auto pstudent = new StudentRaw("Zack", 25, 200);
	pteacher->SetStudent(pstudent);
	pstudent->SetTeacher(pteacher);
	cout << pteacher->GetName() << endl;
	cout << pstudent->GetName() << endl;
	//回收内存，原生指针谁开辟的谁回收
	delete pstudent;
	delete pteacher;
	//所以不使用智能指针的情况下，类中包含外部指针的变量，需要注意放在类外回收
	//但是如果忘记回收或者管理不当，就会造成内存泄漏，比如pstudent和pteacher没有在此处回收
}

void use_weakptr() {
	auto pteacher = make_shared<TeacherWraper>("Herly", 30);
	auto pstudent = shared_ptr<StudentWraper>(new StudentWraper("Zack", 25, 200));
	pteacher->SetStudent(pstudent);
	pstudent->SetTeacher(pteacher);
	cout << pteacher->GetName() << endl;
	cout << pstudent->GetName() << endl;
	cout << pteacher->GetStudent() << endl;
}
