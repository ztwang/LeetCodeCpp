#pragma once

#include <string>
#include <vector>

namespace LeetCode {
using namespace std;
class PermutationSequenceSolution {
public:
	string getPermutation(int n, int k) {
		string nums;
		int divisor = 1;
		int idx = 0;
		for (int i = 1; i <= n; ++i) nums.push_back('0'+i), divisor *= i;
		string result;
		--k;
		for (int i = n; i > 0; --i) {
			divisor /= i;
			idx = k / divisor;
			k = k % divisor;
			result.push_back(nums[idx]), nums.erase(idx, 1);
		}
		return result;
	}
};
}