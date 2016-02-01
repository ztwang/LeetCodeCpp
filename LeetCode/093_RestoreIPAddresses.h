#pragma once

#include <string>
#include <vector>

namespace LeetCode {
using namespace std;
class RestoreIPAddressesSolution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		if (s.size() < 4 || s.size() > 12) return result;
		restore(result, s, "", 0, 4);
		return result;
	}

	void restore(vector<string>& result, string& s, string r, int i, int n) {
		if (n == 0) {
			if (i == s.size()) {
				r.erase(r.end() - 1);
				result.push_back(r);
			}
		}
		else {
			if (i >= s.size() || s.size() - i - 1 > n * 3) return;
			--n;
			string s1 = s.substr(i, 1), s2 = s.substr(i, 2), s3 = s.substr(i, 3);
			restore(result, s, r + s1 + '.', i + 1, n);
			if (s2[0] != '0') restore(result, s, r + s2 + '.', i + 2, n);
			else return;
			if (s3 < "256") restore(result, s, r + s3 + '.', i + 3, n);
		}
	}
};
}