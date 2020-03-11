#include "safequeue.hpp"

void test_safequeue() {
	threadsafe_queue<int> safe_queue;
	safe_queue.push(100);
	if (!safe_queue.empty()) {
		shared_ptr<int> data = safe_queue.wait_and_pop();
		cout << *data << endl;
	}

	safe_queue.push(202);
	if (!safe_queue.empty()) {
		int temp = 0;
		safe_queue.wait_and_pop(temp);
		cout << temp << endl;
	}

	safe_queue.push(303);
	auto data = safe_queue.try_pop();
	cout << *data << endl;

	safe_queue.push(404);
	int temp = 0;
	bool bres = safe_queue.try_pop(temp);
	cout << bres << endl;
	cout << temp << endl;
}
