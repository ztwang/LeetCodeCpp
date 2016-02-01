#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class PlusOneSolution {
public:
	vector<int> plusOne(vector<int>& digits) {
		for (int i = digits.size() - 1; i >= 0; --i) {
			if (digits[i] == 9) {
				digits[i] = 0;
				if (i == 0) {
					digits.insert(digits.begin(), 1);
					return digits;
				}
			}
			else {
				digits[i] = digits[i] + 1;
				return digits;
			}
		}
	}
};
}