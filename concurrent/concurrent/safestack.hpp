#ifndef __SAFESTATCK_H__
#define __SAFESTATCK_H__
#include <iostream>
#include <thread>
#include <string>
#include <memory>
#include <stack>
#include <exception>
#include <mutex>
using namespace std;

struct empty_stack:public exception {
	//throw ²»Å×³öÒì³£
	const char* what() const throw() { return ""; }
};

template <typename T>
class threadsafe_stack {
private:
	std::stack<T> data;
	mutable std::mutex m;
public:
	threadsafe_stack() {}
	threadsafe_stack(const threadsafe_stack & ts) {
		std::lock_guard<mutex>  lg(ts.m);
		data = ts.data;
	}

	threadsafe_stack & operator =(const threadsafe_stack & ts) = delete;

	void push(T new_value) {
		std::lock_guard<mutex> lg(m);
		data.push(new_value);
	}

	std::shared_ptr<T> pop() {
		std::lock_guard<mutex> lg(m);
		if (data.empty()) throw empty_stack();
		const  std::shared_ptr<T>  res(make_shared<T>(data.top()));
		data.pop();
		return res;
	}

	void pop(T& value) {
		std::lock_guard<mutex> lg(m);
		if (data.empty()) throw empty_stack();
		value = data.top();
		data.pop();
	}

	bool empty() const {
		std::lock_guard<mutex> lg(m);
		return data.empty();
	}
};

void test_safestack();
#endif //__SAFESTATCK_H__
