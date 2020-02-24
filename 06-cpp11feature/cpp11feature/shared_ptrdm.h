#ifndef  __SHARED_PTRDM_H__
#define __SHARED_PTRDM_H__
#include <memory>
#include <iostream>
#include <string>
using namespace std;
extern void use_sharedptr();
extern void use_uniqueptr();
extern void use_weakptr();
extern void raw_ptr();

class Student {
public:
	Student(string name, int age, int score):m_strname(name),m_nage(age),m_nscore(score){}
	Student() = default;
	string GetName() { return m_strname; }
private:
	string m_strname;
	int m_nage;
	int m_nscore;
};

class TeacherRaw;
class StudentRaw {
public:
	StudentRaw(string name, int age, int score) :m_strname(name), m_nage(age), m_nscore(score) {}
	StudentRaw() = default;
	string GetName() { return m_strname; }
	void SetTeacher(TeacherRaw * pTeacher) {
		m_pTeacher = pTeacher;
	}
	~StudentRaw() {
		//teacher 和 student类里有双方指针，所以不能delete，
		//否则会造成析构函数递归调用，内存崩溃。
		//谁开辟的内存谁回收，这样安全，回收teacher放在外边开辟的类或cpp中
		//delete m_pTeacher;  
		m_pTeacher = nullptr;
	}
private:
	string m_strname;
	int m_nage;
	int m_nscore;
	TeacherRaw * m_pTeacher;
};

class TeacherRaw {
public:
	TeacherRaw(string name, int age) :m_strname(name), m_nage(age){}
	TeacherRaw() = default;
	string GetName() { return m_strname; }
	void SetStudent(StudentRaw* p) {
		m_pStudent = p;
	}
	~TeacherRaw() {
		//teacher 和 student类里有双方指针，所以不能delete，
		//否则会造成析构函数递归调用，内存崩溃。
		//谁开辟的内存谁回收，这样安全，回收studentr放在外边开辟的类或cpp中
		//delete m_pStudent; 
		m_pStudent = nullptr;
	}
private:
	string m_strname;
	int m_nage;
	StudentRaw * m_pStudent;
};

class TeacherWraper;
class StudentWraper{
public:
	StudentWraper(string name, int age, int score) :m_strname(name), m_nage(age), m_nscore(score) {}
	StudentWraper() = default;
	string GetName() { return m_strname; }
	void SetTeacher(shared_ptr<TeacherWraper> pTeacher) {
		m_pTeacher = pTeacher;
	}
	~StudentWraper() {
		//m_pTeacher是智能指针，不需要手动回收
	}
private:
	string m_strname;
	int m_nage;
	int m_nscore;
	shared_ptr<TeacherWraper>  m_pTeacher;
};

class TeacherWraper {
public:
	TeacherWraper(string name, int age) :m_strname(name), m_nage(age) {}
	TeacherWraper() = default;
	string GetName() { return m_strname; }
	string GetStudent() {
		//判断引用计数是否为0
		//expired返回true等同于 usecount == 0
		if (m_pStudent.expired()) {
			return "";
		}
		//通过lock()函数构造出shared_ptr对象，可以继续访问对象的函数和数据
		return m_pStudent.lock()->GetName();
		
	}
	void SetStudent(shared_ptr<StudentWraper> p) {
		m_pStudent = p;
	}
	~TeacherWraper() {
	}
private:
	string m_strname;
	int m_nage;
	//此处不能用shared_ptr，因为彼此引用对方的shared_ptr会造成循环引用
	//循环引用会造成内存泄漏，当回收teacher时要回收student，回收student要回收teacher，就锁住了
	//shared_ptr<StudentWraper>  m_pStudent;
	//使用weakptr，不会造成循环引用问题
	weak_ptr<StudentWraper> m_pStudent;
};

#endif

