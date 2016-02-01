#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class MergeSortedArraySolution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (n == 0) return;
		if (m == 0) {
			for (int i = 0; i<n; ++i) nums1[i] = nums2[i];
			return;
		}
		int total = m + n;
		--m; --n;
		while (total-- > 0) {
			if (n < 0) break;
			if (m >=0 && nums1[m] > nums2[n]) {
				nums1[total] = nums1[m--];
			}
			else nums1[total] = nums2[n--];
		}
	}
};
}