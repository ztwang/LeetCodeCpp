#pragma once

namespace LeetCode {
class SqrtSolution {
public:
	int mySqrt(int x) {
		if (x == 0) return 0;
		if (x < 4) return 1;
		int begin = 0;
		int end = x / 2 + 1;
		while (begin < end - 1) {
			int mid = (begin + end) / 2;
			if (mid == x / mid) return mid;
			if (mid > x / mid) end = mid;
			else begin = mid;
		}
		return begin;
	}
};
}