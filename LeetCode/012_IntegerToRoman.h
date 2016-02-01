#pragma once

#include <string>

namespace LeetCode {
using namespace std;
class IntegerToRomanSolution {
public:
	string intToRoman(int num) {
		char romans [9] { 'I', 'V', 'X', 'L', 'C', 'D', 'M', ' ', ' '};
		string r;
		int i = 0;
		while (num > 0) {
			r = getRoman(num%10, romans[i], romans[i + 1], romans[i + 2]) + r;
			num /= 10;
			i += 2;
		}
		return r;
	}
	
	string getRoman(int n, char one, char five, char ten) {
		string r;
		switch (n) {
		case 3:
			r.push_back(one);
		case 2:
			r.push_back(one);
		case 1:
			r.push_back(one);
			break;
		case 4:
			r.push_back(one);
			r.push_back(five);
			break;
		case 5:
			r.push_back(five);
			break;
		case 6:
			r.push_back(five);
			r.push_back(one);
			break;
		case 7:
			r.push_back(five);
			r.push_back(one);
			r.push_back(one);
			break;
		case 8:
			r.push_back(five);
			r.push_back(one);
			r.push_back(one);
			r.push_back(one);
			break;
		case 9:
			r.push_back(one);
			r.push_back(ten);
			break;
		}
		return r;
	}
};
}