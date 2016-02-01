#pragma once

#include <string>

namespace LeetCode {
using namespace std;
class TrieNode {
public:
	bool end;
	TrieNode* next[26]{ nullptr };
	// Initialize your data structure here.
	TrieNode() {
		end = false;
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode* pivot = root;
		for (char c : word) {
			if (pivot->next[c - 'a'] == nullptr) {
				pivot->next[c - 'a'] = new TrieNode();
			}
			pivot = pivot->next[c - 'a'];
		}
		pivot->end = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* pivot = root;
		for (char c : word) {
			if (pivot->next[c - 'a'] == nullptr) {
				return false;
			}
			pivot = pivot->next[c - 'a'];
		}
		return pivot != nullptr && pivot->end;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode* pivot = root;
		for (char c : prefix) {
			if (pivot->next[c - 'a'] == nullptr) {
				return false;
			}
			pivot = pivot->next[c - 'a'];
		}
		return pivot != nullptr;
	}

private:
	TrieNode* root;
};
}