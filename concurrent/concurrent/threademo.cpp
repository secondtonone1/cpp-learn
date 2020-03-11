#include "threademo.hpp"

void hello_world() {
	cout << "Hello World!" << endl;
}

void other_world() {
	cout << "Other World!" << endl;
}

void use_thread() {
	thread t(hello_world);
	t.join();
}

//ʹ��detach���������̻߳������ȫ���⡣
//��Ϊ�߳������������̵߳ľֲ�������
void unsafe_detach() {
	int nstate = 1;
	auto funvar = func(nstate);
	std::thread  thread_fun(funvar);
	thread_fun.detach();
}

//RAII, ��Դ��ȡ����ʼ��(resource acquisition is initialize)
void safe_guard() {
	int nstate = 1;
	func funvar(nstate);
	std::thread  func_thread(funvar);
	thread_guard tg (func_thread);
	//���߳̿��Լ�����������飬�����߳���tg��ʼ��������tg����ʱ���Զ�����join����֤���̵߳ȴ����߳��˳�
}

void print_data(int  i, const string& str) {
	cout << "i is " << i << endl;
	cout << "str is  " << str << endl;
}

void param_thread() {
	int state = 100;
	char buff[1024] = "Hello World!";
	//�˴�ʹ��string����һ���ֲ����������ֱ��ʹ��buff��buff�Ǹ�ָ�룬���߳��˳�buff���գ����̻߳�������⡣
	thread paramt(print_data, state, string(buff));
	//����print_data����̺߳����Ḵ��string��ֵ��print_data��str������ʵ�Ǿֲ�����string(buff)�����á�
	paramt.detach();
}

void update_data(int& state, string & str) {
	state = 1024;
	str = "Hello, Zack!";
}

void update_data2(int& state, const string & str) {
	state = 788;
}
void update_thread() {
	int state = 100;
	string str = "It dosen't matter";
	//std::ref ����ȡstate�����ô���
	//�߳�ͨ���������Ͳ���bindһ�𣬹����һ���µĻص��������ݸ��̡߳�
	//bind��֪���Լ����ɵĺ������õ�ʱ������Ƿ���Ч������ѡ��ֵ���ݣ������Ҫָ�����ô��ݿ���ͨ��ref
	//�����Ҫָ��const���ã�����ͨ��cref
	thread updateparam(update_data, std::ref(state), std::ref(str));
	updateparam.join();
	cout << "state is " << state << endl;
	cout << "str is " << str << endl;
	auto bindf = std::bind(update_data2, std::ref(state), std::cref(str));
	bindf();
	cout << "state is " << state << endl;
	cout << "str is " << str << endl;
}

void bind_param() {
	int state = 1024;
	string str = "Zack Web";
	func funcobj(state);
	auto bind_print = std::bind(&func::print_data, &funcobj, std::cref(str));
	bind_print();
	//ͬ������һ���̣߳��̻߳ص���������ĳ�Ա������������б��bindһ��
	std::thread  memthread(&func::print_data, &funcobj, std::cref(str));
	memthread.join();
}

void move_thread() {
	//t1��helloworld��
	std::thread  t1(hello_world);
	//��t1������Ȩת�Ƹ�t2,����t2��helloworld��
	std::thread t2 = std::move(t1);
	//t3��other_world
	std::thread t3(other_world);
	//t1�Ѿ�������Ȩ�ˣ���ʱ��t3����Ȩת�Ƹ�t1�������
	//t1 = move(t3);
}

void use_scopethread() {
	int locate_state = 1024;
	scope_thread(thread(func(locate_state)));
	cout << locate_state << endl;
}