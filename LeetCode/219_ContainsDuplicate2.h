#pragma once

#include <vector>
#include <unordered_map>

namespace LeetCode {
using namespace std;
class ContainsDuplicate2Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (k <= 0) return false;
		int size = nums.size();
		if (k >= size) k = size - 1;
		unordered_map<int, int> record;
		for (int i = 0; i<size; ++i) {
			if (record.find(nums[i]) != record.end() && i - record[nums[i]] <= k) return true;
			else record[nums[i]] = i;
		}
		return false;
	}
};
}