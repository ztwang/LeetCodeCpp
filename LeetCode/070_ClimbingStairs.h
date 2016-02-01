#pragma once

namespace LeetCode {
class ClimbingStairsSolution {
public:
	int climbStairs(int n) {
		static int counts[100];
		if (n < 0) return 0;
		if (n < 2) return 1;
		if (counts[n] > 0) {
			return counts[n];
		}
		else {
			int c = climbStairs(n - 1) + climbStairs(n - 2);
			counts[n] = c;
			return c;
		}

	}
};
}