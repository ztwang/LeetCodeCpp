#pragma once

#include <string>
#include <unordered_map>

namespace LeetCode {
using namespace std;
class WordPatternSolution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<char, string> pmap;
		unordered_map<string, char> smap;
		int start = 0;
		for (char p : pattern) {
			if (start >= str.size()) return false;
			int end = start + 1;
			while (end < str.size() && str[end] != ' ') ++end;
			string s = str.substr(start, end - start);
			if (pmap.find(p) == pmap.end()) {
				if (smap.find(s) == smap.end()) {
					pmap[p] = s;
					smap[s] = p;
				}
				else return false;
			}
			else {
				if (s != pmap[p]) return false;
			}
			start = end + 1;
		}
		return start >= str.size();
	}
};
}