#pragma once

#include <stack>

namespace LeetCode {
using namespace std;
class MinStack {
private:
	stack<int> min;
	stack<int> nums;
public:
	void push(int x) {
		nums.push(x);
		if (min.empty() || x <= min.top()) min.push(x);
	}

	void pop() {
		if (nums.empty()) return;
		if (min.top() == nums.top()) min.pop();
		nums.pop();
	}

	int top() {
		return nums.top();
	}

	int getMin() {
		return min.top();
	}
};
}