#pragma once

#include <string>
#include <stack>

namespace LeetCode {
using namespace std;
class ValidParenthesesSolution {
public:
	bool isValid(string s) {
		stack<char> stk;
		for (char c : s) {
			if (c == ')') {
				if (stk.size() == 0) return false;
				if (stk.top() != '(') return false;
				stk.pop();
			}
			else if (c == ']') {
				if (stk.size() == 0) return false;
				if (stk.top() != '[') return false;
				stk.pop();
			}
			else if (c == '}') {
				if (stk.size() == 0) return false;
				if (stk.top() != '{') return false;
				stk.pop();
			}
			else {
				stk.push(c);
			}
		}
		return stk.empty();
	}
};
}