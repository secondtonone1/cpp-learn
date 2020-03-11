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

//使用detach分离主从线程会产生安全问题。
//因为线程中引用了主线程的局部变量。
void unsafe_detach() {
	int nstate = 1;
	auto funvar = func(nstate);
	std::thread  thread_fun(funvar);
	thread_fun.detach();
}

//RAII, 资源获取即初始化(resource acquisition is initialize)
void safe_guard() {
	int nstate = 1;
	func funvar(nstate);
	std::thread  func_thread(funvar);
	thread_guard tg (func_thread);
	//主线程可以继续做别的事情，而子线程由tg初始化，并且tg析构时会自动调用join，保证主线程等待子线程退出
}

void print_data(int  i, const string& str) {
	cout << "i is " << i << endl;
	cout << "str is  " << str << endl;
}

void param_thread() {
	int state = 100;
	char buff[1024] = "Hello World!";
	//此处使用string构造一个局部变量，如果直接使用buff，buff是个指针，主线程退出buff回收，子线程会出现问题。
	thread paramt(print_data, state, string(buff));
	//就是print_data这个线程函数会复制string的值，print_data的str参数其实是局部变量string(buff)的引用。
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
	//std::ref 可以取state的引用传递
	//线程通过将函数和参数bind一起，构造成一个新的回调函数传递给线程。
	//bind不知道自己生成的函数调用的时候参数是否还有效，所以选择值传递，如果想要指定引用传递可以通过ref
	//如果想要指定const引用，可以通过cref
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
	//同样启动一个线程，线程回调函数是类的成员函数，其参数列表和bind一样
	std::thread  memthread(&func::print_data, &funcobj, std::cref(str));
	memthread.join();
}

void move_thread() {
	//t1和helloworld绑定
	std::thread  t1(hello_world);
	//将t1的所有权转移给t2,这样t2和helloworld绑定
	std::thread t2 = std::move(t1);
	//t3绑定other_world
	std::thread t3(other_world);
	//t1已经有所有权了，此时将t3所有权转移给t1会出问题
	//t1 = move(t3);
}

void use_scopethread() {
	int locate_state = 1024;
	scope_thread(thread(func(locate_state)));
	cout << locate_state << endl;
}