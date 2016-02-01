#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>

namespace LeetCode {
using namespace std;
class GroupAnagramsSolution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> results;
		unordered_map<string, vector<string>> map;
		results.clear();
		map.clear();
		sort(strs.begin(), strs.end());
		for (string str : strs) {
			string s = str;
			sort(s.begin(), s.end());
			map[s].push_back(str);
		}
		for (auto iter = map.begin(); iter != map.end(); ++iter) {
			results.push_back(iter->second);
		}
		return results;
	}
};
}