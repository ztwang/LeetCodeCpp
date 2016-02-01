#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class MajorityElementSolution {
public:
	int majorityElement(vector<int>& nums) {
		int result = 0, count = 0;
		for (int n : nums) {
			if (!count) result = n;
			n == result ? ++count : --count;
		}
		return result;
	}
};
}