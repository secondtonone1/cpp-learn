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
		//teacher �� student������˫��ָ�룬���Բ���delete��
		//�����������������ݹ���ã��ڴ������
		//˭���ٵ��ڴ�˭���գ�������ȫ������teacher������߿��ٵ����cpp��
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
		//teacher �� student������˫��ָ�룬���Բ���delete��
		//�����������������ݹ���ã��ڴ������
		//˭���ٵ��ڴ�˭���գ�������ȫ������studentr������߿��ٵ����cpp��
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
		//m_pTeacher������ָ�룬����Ҫ�ֶ�����
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
		//�ж����ü����Ƿ�Ϊ0
		//expired����true��ͬ�� usecount == 0
		if (m_pStudent.expired()) {
			return "";
		}
		//ͨ��lock()���������shared_ptr���󣬿��Լ������ʶ���ĺ���������
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
	//�˴�������shared_ptr����Ϊ�˴����öԷ���shared_ptr�����ѭ������
	//ѭ�����û�����ڴ�й©��������teacherʱҪ����student������studentҪ����teacher������ס��
	//shared_ptr<StudentWraper>  m_pStudent;
	//ʹ��weakptr���������ѭ����������
	weak_ptr<StudentWraper> m_pStudent;
};

#endif

