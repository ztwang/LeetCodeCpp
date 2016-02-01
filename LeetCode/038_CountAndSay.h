#pragma once

#include <string>

namespace LeetCode {
using namespace std;
class CountAndSaySolution {
public:
	string countAndSay(int n) {
		string s = "1";
		if (n < 2) return "1";
		for (int i = 1; i < n; ++i) {
			count(s, i);
		}
		return s;
	}

	void count(string& s, int n) {
		string result;
		char prev = s[0];
		int count = 1;
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] != prev) {
				result.push_back(count + '0');
				result.push_back(prev);
				count = 1;
			}
			else {
				++count;
			}
			prev = s[i];
		}
		result.push_back(count + '0');
		result.push_back(s[s.size() - 1]);
		s = result;
	}
};
}