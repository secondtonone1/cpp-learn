#ifndef __THREAD_DEMO_H__
#define __THREAD_DEMO_H__
#include <iostream>
#include <thread>
#include <string>
using namespace std;

extern void use_thread();

class  func {
public:
	int & i;
	func(int &_i):i(_i){}
	func() = default;
	void operator()() {
		for (int i = 0; i < 1000; i++) {
			cout << i << endl;
		}
	}
	void print_data(const string &str) {
		i = 202;
		cout << i << endl;
		cout << str << endl;
	}
};

extern void unsafe_detach();
class thread_guard {
public:
	thread_guard(thread & t):m_t(t){}
	~thread_guard() {
		if (m_t.joinable()) {
			m_t.join();
		}
	}
	thread_guard(const thread_guard & tg) = delete;
	thread_guard& operator = (const thread_guard &) = delete;
private:
	thread & m_t;
};

extern void safe_guard();
extern void param_thread();
extern void update_thread();
extern void bind_param();
extern void move_thread();

class scope_thread {
public:
	scope_thread() = default;
	explicit scope_thread(std::thread t):m_thread(move(t)){
		if (!m_thread.joinable()) {
			throw std::logic_error("thread has been moved");
		}
	}
	~scope_thread() {
		m_thread.join();
	}
	scope_thread(const scope_thread &) = delete;
	scope_thread & operator = (const scope_thread &) = delete;
private:
	thread m_thread;
};

extern void use_scopethread();
#endif

