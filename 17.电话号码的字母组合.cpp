/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
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
    const string _digitMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
    vector<string> _res;
    string _path;

    void backtrack(string& digits, int index) {
        if (index == digits.length()) {
            _res.push_back(_path);
            return;
        }
        // 取当前索引对应字符串
        for (char c : _digitMap[digits[index] - '0']) {
            _path.push_back(c);
            backtrack(digits, index + 1);
            _path.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return _res;
        backtrack(digits, 0);
        return _res;
    }
};
// @lc code=end

