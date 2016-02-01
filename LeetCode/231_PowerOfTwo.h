#pragma once

namespace LeetCode {
class PowerOfTwoSolution {
public:
	bool isPowerOfTwo(int n) {
		if (n < 1) return false;
		return !(n & n - 1);
	}
};
}