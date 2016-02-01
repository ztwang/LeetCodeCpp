#pragma once

#include <vector>
#include "BinaryTree.h"

namespace LeetCode {
using namespace std;
class ConvertSortedArrayToBSTSolution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return build(nums, 0, nums.size() - 1);
	}

	TreeNode* build(vector<int>& nums, int m, int n) {
		if (m > n) return nullptr;
		if (m == n) return new TreeNode(nums[m]);
		int mid = m + (n - m + 1) / 2;
		TreeNode* node = new TreeNode(nums[mid]);
		node->left = build(nums, m, mid - 1);
		node->right = build(nums, mid + 1, n);
		return node;
	}
};
}