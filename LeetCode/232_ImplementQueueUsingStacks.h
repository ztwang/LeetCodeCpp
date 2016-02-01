#pragma once

#include <stack>

namespace LeetCode {
using namespace std;
class StackQueue {
private:
	stack<int> s;
	stack<int> t;
public:
	// Push element x to the back of queue.
	void push(int x) {
		s.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {

		int size1 = s.size();
		int size2 = size1;
		while (--size1) {
			t.push(s.top());
			s.pop();
		}
		s.pop();
		while (--size2) {
			s.push(t.top());
			t.pop();
		}
	}

	// Get the front element.
	int peek(void) {
		int size1 = s.size();
		int size2 = size1;
		while (--size1) {
			t.push(s.top());
			s.pop();
		}
		int result = s.top();
		while (--size2) {
			s.push(t.top());
			t.pop();
		}
		return result;
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return s.empty();
	}
};
}