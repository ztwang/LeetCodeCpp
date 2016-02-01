#pragma once

#include <vector>
#include <algorithm>

namespace LeetCode {
using namespace std;
class ContainerWithMostWaterSolution {
public:
	int maxArea(vector<int>& height) {
		int max = 0;
		int p1 = 0, p2 = height.size()-1;
		while (p2 > p1) {
			int a = (p2 - p1)*min(height[p2], height[p1]);
			if (a > max) max = a;
			if (height[p2] > height[p1]) p1++;
			else p2--;
		}
		return max;
	}
};
}