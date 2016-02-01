#pragma once

#include <string>
#include <vector>

namespace LeetCode {
using namespace std;
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> result;
		int size = nums.size();
		if (!size) return result;
		int start = nums[0], cur = start;
		for (int i = 1; i<size; ++i) {
			if (nums[i] == cur + 1) {
				cur = nums[i];
				continue;
			}
			else {
				if (start == cur) result.push_back(to_string(start));
				else result.push_back(to_string(start) + "->" + to_string(cur));
				cur = start = nums[i];
			}
		}
		if (start == cur) result.push_back(to_string(start));
		else result.push_back(to_string(start) + "->" + to_string(cur));
		return result;
	}
};
}