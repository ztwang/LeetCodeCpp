#pragma once

namespace LeetCode {
bool isBadVersion(int version);

class FirstBadVersionSolution {
public:
	int firstBadVersion(int n) {
		int begin = 0, end = n;
		while (begin < end - 1) {
			int mid = begin + (end - begin) / 2;
			if (isBadVersion(mid)) {
				end = mid;
			}
			else {
				begin = mid;
			}
		}
		return begin + 1;
	}
};
}