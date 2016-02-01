#pragma once

#include <vector>
#include <algorithm>

namespace LeetCode {
using namespace std;
class BestTimeToBuyAndSellStock2Solution {
public:
	int maxProfit(vector<int>& prices) {
		int r = 0;
		for (int i = 1; i<prices.size(); ++i) {
			r += max(prices[i] - prices[i - 1], 0);
		}
		return r;
	}
};
}