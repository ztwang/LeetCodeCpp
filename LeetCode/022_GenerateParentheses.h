#pragma once

#include <string>
#include <vector>

namespace LeetCode {
using namespace std;
class GenerateParenthesesSolution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> results;
		generate(results, "", n, n);
		return results;
	}

	void generate(vector<string>& results, string result, int l, int r) {
		if (l == 0 && r == 0) results.push_back(result);
		else {
			if (l > 0) {
				generate(results, result+'(', l - 1, r);
			}
			if (l < r) {
				generate(results, result+')', l, r - 1);
			}
		}
	}
};
}