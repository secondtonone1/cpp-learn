#ifndef __SAFEQUEUE_H__
#define __SAFEQUEUE_H__
#include <iostream>
#include <thread>
#include <string>
#include <memory>
#include <stack>
#include <exception>
#include <mutex>
#include <queue>
#include <condition_variable>
using namespace std;

template <typename T>
class threadsafe_queue {
private:
	std::queue<T> data_queue;
	mutable std::mutex mut;
	std::condition_variable data_cond;
public:
	threadsafe_queue() {}
	threadsafe_queue(const threadsafe_queue & other) {
		std::lock_guard<mutex>  lg(other.mut);
		data_queue = other.data_queue;
	}

	threadsafe_queue & operator =(const threadsafe_queue & ts) = delete;

	void push(T new_value) {
		std::lock_guard<mutex> lg(mut);
		data_queue.push(new_value);
		//只通知一个
		data_cond.notify_one();
	}
	
	void wait_and_pop(T& value) {
		std::unique_lock<mutex> ul(mut);
		//wait条件为真，则继续往下执行
		//wait条件为false，则挂起线程，释放mutex
		
		data_cond.wait(ul,
				[this]() {
			return !data_queue.empty();
		});

		value = data_queue.front();
		data_queue.pop();
	}
	
	shared_ptr<T> wait_and_pop() {
		std::unique_lock<mutex> ul(mut);
		//wait条件为真，则继续往下执行
		//wait条件为false，则挂起线程，释放mutex
		data_cond.wait(ul, 
			[this]()->bool{
			return !data_queue.empty(); 
		});
		shared_ptr<T> 	value = make_shared<T>(data_queue.front());
		data_queue.pop();
		return value;
	}

	bool empty() const {
		std::lock_guard<mutex> lg(mut);
		return data_queue.empty();
	}

	bool try_pop(T& value) {
		std::lock_guard<mutex> lg(mut);
		if (data_queue.empty()) {
			return false;
		}
		value = data_queue.front();
		data_queue.pop();
		return true;
	}

	shared_ptr<T> try_pop() {
		std::lock_guard<mutex> lg(mut);
		if (data_queue.empty()) {
			return make_shared<T>();
		}
		auto value =  std::make_shared<T>(data_queue.front());
		data_queue.pop();
		return value;
	}
};

void test_safequeue();
#endif //__SAFEQUEUE_H__
//