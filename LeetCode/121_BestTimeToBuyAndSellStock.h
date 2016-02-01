#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class BestTimeToBuyAndSellStockSolution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2) return 0;
		int result = 0, min = prices[0];
		for (int i = 1; i<prices.size(); ++i) {
			int p = prices[i] - min;
			if (p > result) result = p;
			if (prices[i] < min) min = prices[i];
		}
		return result;
	}
};
}