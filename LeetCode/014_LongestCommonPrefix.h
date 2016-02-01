#pragma once

#include <string>
#include <vector>

namespace LeetCode {
using namespace std;
class LongestCommonPrefixSolution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
		if (strs.size() == 1) return strs[0];
		int i = 0;
		char c = strs[0][0];
		bool end = false;
		while (true) {
			for (int j = 1; j<strs.size(); ++j) {
				if (i == strs[j].size() || strs[j][i] != c) {
					end = true;
					break;
				}
			}
			if ( end ) return strs[0].substr(0, i);
			c = strs[0][++i];
		}
	}
};
}