#pragma once

#include <string>

namespace LeetCode {
class StringToIntegerSolution {
public:
	int myAtoi(std::string str) {
		int flag = 1;
		int i = 0;
		while (str[i] == ' ') i++;
		if (str[i] == '+') flag = 1, str.erase(i, 1);
		else if (str[i] == '-') flag = -1, str.erase(i, 1);
		long long r = 0;
		int size = str.size();
		for (; i < size; ++i) {
			if (str[i] <= '9' && str[i] >= '0') {
				r = r * 10 + str[i] - '0';
				if (r * flag > INT_MAX) return INT_MAX;
				if (r * flag < INT_MIN) return INT_MIN;
			}
			else break;
		}
		return r * flag;
	}
};
}