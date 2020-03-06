#ifndef  __LAMBDA_DEMO_H__
#define __LAMBDA_DEMO_H__
#include <string>
#include <iostream>
#include <list>
#include <functional>
using lambfunc = std::function<int(int a, int b)>;
using namespace std;
extern void use_lambda();
extern void push_func();
extern void test_lambdalife();
class LambQueue {
public:
	LambQueue() = default;
	void push_back(const lambfunc & fun) {
		m_funlist.push_back(fun);
	}
	bool  pop_front( lambfunc & lb) {
		if (m_funlist.empty()) {
			return false;
		}
		lb = m_funlist.front();
		m_funlist.pop_front();
		return true;
	}
private:
	std::list<lambfunc> m_funlist;
};
#endif  __LAMBDA_DEMO_H__


