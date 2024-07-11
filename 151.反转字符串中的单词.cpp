/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// #include "include/leetcode_structures.h"
// #include <string>
// #include <vector>
// using namespace std;

// @lc code=start
class Solution {
private:
    void reverse(string& s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }

public:
    string reverseWords(string s) {
        reverse(s, 0, s.size() - 1);
        bool inWord = false;
        bool isStart = true;
        int left = 0;
        string res;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ' && !inWord) {
                if (!isStart) {
                    res += ' ';
                } else {
                    isStart = false;
                }
                inWord = true;
                left = i;
            } else if (s[i] == ' ' && inWord) {
                inWord = false;
                reverse(s, left, i - 1);
                res += s.substr(left, i - left);
            }
        }
        if (inWord) {
            reverse(s, left, s.size() - 1);
            res += s.substr(left, s.size() - left);
        }
        return res;
    }
};
// @lc code=end

