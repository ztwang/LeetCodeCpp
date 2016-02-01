#pragma once

#include <queue>

namespace LeetCode {
using namespace std;
class QueueStack {
private:
	queue<int> q;
public:
	// Push element x onto stack.
	void push(int x) {
		q.push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		if (q.empty()) return;
		int size = q.size();
		while (--size) {
			q.push(q.front());
			q.pop();
		}
		q.pop();
	}

	// Get the top element.
	int top() {
		return q.back();
	}

	// Return whether the stack is empty.
	bool empty() {
		return q.empty();
	}
};
}