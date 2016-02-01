#pragma once

#include <string>

namespace LeetCode {
using namespace std;
class SimplifyPathSolution {
public:
	string simplifyPath(string path) {
		int n = path.size();
		int skip = 0;
		string result;
		while (n > 0) {
			while (path[--n] == '/'); // left path start
			if (n <= 0) break;
			int m = n;
			while (path[m] != '/') --m;
			string p = path.substr(m, n - m + 1);
			if (p == "/.") {
				n = m;
				continue;
			}
			else if (p == "/..") {
				n = m;
				skip -= 1;
				continue;

			}
			else if (skip < 0) {
				n = m;
				++skip;
				continue;
			}
			else {
				result = p + result;
				n = m;
				continue;
			}
		}
		if (result.size() == 0) return "/";
		return result;
	}
};
}