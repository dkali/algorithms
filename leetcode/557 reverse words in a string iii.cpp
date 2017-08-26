// https://leetcode.com/problems/reverse-words-in-a-string-iii

// Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// Example 1:
// Input: "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Note: In the string, each word is separated by single space and there will not be any extra space in the string.

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
	int cursor;
	string str;

	bool findWord(int &start, int &end) {
		if (cursor == str.length())
			return false; //no more words

		// find word border
		start = cursor;
		for (int i = cursor; i < str.length(); i++){
			if (str.at(i) != ' '){
				cursor++;
				end = i;
			}
			else {
				cursor++;
				break;
			}
		}

		return true; //word found
	}

	void reverse_word(int start_index, int end_index) {
		for (int st = start_index, end = end_index; st < end; st++, end--) {
			char tmp = str.at(st);
			str[st] = str[end];
			str[end] = tmp;
		}
	}

public:
	Solution() {
		cursor = 0;
	}

	string reverseWords(string s) {
		cursor = 0;
		str = s;

		int start = 0, end = 0;

		while (findWord(start, end) == true) {
			reverse_word(start, end);
		}

		return str;
	}
};