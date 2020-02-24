#include "shared_ptrdm.h"
#include <memory>
#include <iostream>
using namespace std;
void use_sharedptr() {
	//ָ��int���͵�����ָ�룬shared_ptr�������Ÿ�ֵ�����ã��������ü���
	//�Զ��������������������ü���Ϊ0���������Դ
	shared_ptr<int>  sh_n = shared_ptr<int>(new int(5));
	//ע��˴�use_countΪshared_ptr��ĳ�Ա������������.
	cout << sh_n.use_count() << endl;
	//shared_ptrȡ���Ա����Ҫ��->
	shared_ptr<Student> student_p = shared_ptr<Student>(new Student("Zack", 25, 100));
	cout << student_p->GetName() << endl;
	//����ʹ��*������
	cout << *sh_n << endl;
	//shared_ptr֧�ָ�ֵ���������ü�������1
	shared_ptr<int> sh_n2 = sh_n;
	//������ü���
	cout << sh_n.use_count() << endl;
	//shared_ptr ֧��copy����
	shared_ptr<int> sh_n3(sh_n);
	cout << sh_n3.use_count() << endl;
	//shared_ptr �Ĳ������캯��Ҳ֧��ԭ��ָ��
	shared_ptr<int> sh_n4(new int(8));
	//����ָ��ĳ�ʼ���ô���Ϊ1
	cout << sh_n4.use_count() << endl;
	//����ָ����һ�ֹ��췽ʽ,������д���캯���Ĳ�������
	shared_ptr<int> sh_n5 = make_shared<int>(1024);
	//������ָ�뻹ԭΪԭ��ָ��
	int * raw_p =sh_n5.get();
	cout << *raw_p << endl;
}
unique_ptr<Student>  return_unique() {
	unique_ptr<Student> us = unique_ptr<Student>(new Student("Temp", 20, 20));
	return us;
}
void use_uniqueptr() {
	//unique ptr ����ָ��ָ�����Դ�Ƕ�ռ�ģ�
	//ͨ����ֵ�����ָ�룬������ǰunique_ptr����Դ��ռ��
	unique_ptr<Student> us1 = unique_ptr<Student>(new Student("Zack", 26, 120));
	cout << us1->GetName() << endl;
	//������һ��unique_ptr����ֵ����һ��,�������unique_ptr����ֵ�����ڵ�ǰ�����������ͷ�
	// unique_ptr �ĸ�ֵ�����ѱ�ɾ��
   //	unique_ptr<Student> us2 = us1;
	//���ǿ���ͨ����ʱ����(��ֵ)��ʼ����һ��unique_ptr
	unique_ptr<Student> us2 = unique_ptr<Student>(new Student("Rolin", 25, 229));
	cout << us2->GetName() << endl;
	//Ҳ����ͨ��һ����������unique_ptr��ֵ����һ��unique_ptr����,��Ϊ�ֲ���unique_ptr�ں�������������
	unique_ptr<Student> us3 = return_unique();
	cout << us3->GetName() << endl;
	//����ͨ��std::move ת��unique������Ȩ��������ת�Ƶ�unique�޷�����ʹ��
	unique_ptr<Student> us4 = std::move(us1);
	cout << us4->GetName() << endl;
	//����Ȩ��ת�ƣ������޷�����ʹ��us1
	//cout << us1->GetName() << endl;
	//unique ����ͨ��release�Զ��ͷ���Դ����Ȩ
	us4.release();
	//us4Ҳ�޷�ʹ��
	//us4->GetName();
}

//��ʹ������ָ�룬�����ڴ�Ҫע������λ���
//ҲҪע������ٻ�������ڴ�й©
void raw_ptr() {
	auto pteacher = new TeacherRaw("Herly", 30);
	auto pstudent = new StudentRaw("Zack", 25, 200);
	pteacher->SetStudent(pstudent);
	pstudent->SetTeacher(pteacher);
	cout << pteacher->GetName() << endl;
	cout << pstudent->GetName() << endl;
	//�����ڴ棬ԭ��ָ��˭���ٵ�˭����
	delete pstudent;
	delete pteacher;
	//���Բ�ʹ������ָ�������£����а����ⲿָ��ı�������Ҫע������������
	//����������ǻ��ջ��߹��������ͻ�����ڴ�й©������pstudent��pteacherû���ڴ˴�����
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
