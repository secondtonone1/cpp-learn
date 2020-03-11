#include "safestack.hpp"

void test_safestack() {
	threadsafe_stack<int> safe_stack;
	safe_stack.push(100);
	if (!safe_stack.empty()) {
		shared_ptr<int>  data = safe_stack.pop();
		cout << *data << endl;
	}
	safe_stack.push(200);
	if (!safe_stack.empty()) {
		int temp = 0;
		safe_stack.pop(temp);
		cout << temp << endl;
	}
}
