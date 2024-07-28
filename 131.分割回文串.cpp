/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
// #include "include/leetcode_structures.h"
// #include <vector>
// #include <string>
// #include <stack>
// #include <queue>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;

// @lc code=start
class Solution {
private:
    vector<vector<string>> _res;
    vector<string> _path;
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

    void backtrack(string& s, int index) {
        if (index == s.length()) {
            _res.push_back(_path);
            return;
        }
        for (int i = index; i < s.length(); ++i) {
            if (!isPalindrome(s, index, i)) {
                continue;
            }
            _path.push_back(s.substr(index, i - index + 1));
            backtrack(s, i + 1);
            _path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return _res;
    }
};
// @lc code=end

