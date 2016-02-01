/*
 * TwoSum.h
 *
 *  Created on: Dec 27, 2015
 *      Author: wzt
 */

#ifndef TWOSUM_H_
#define TWOSUM_H_

#include <unordered_map>
#include <vector>
#include <algorithm>

namespace LeetCode {
class TwoSumSolution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); ++i) {
			int x = nums[i];
			int y = target - x;
			if (map.find(y) != map.end()) {
				std::vector<int> result(0);
				result.push_back(map[y]);
				result.push_back(i + 1);
				return result;
			}
			map[x] = i + 1;
		}
	}
};
}

#endif /* TWOSUM_H_ */
