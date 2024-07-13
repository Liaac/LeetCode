/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
// #ifndef ONLINE_JUDGE
// #include "include/leetcode_structures.h"
// #include <vector>
// #include <string>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;
// #endif

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> bracketStack;
        unordered_map<char, char> bracketMap = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        for (char c : s) {
            if (bracketMap.find(c) == bracketMap.end()) {
                bracketStack.push(c);
            } else {
                if (bracketStack.empty() || bracketStack.top() != bracketMap[c]) {
                    return false;
                }
                bracketStack.pop();
            }
        }
        return bracketStack.empty();
    }
};
// @lc code=end

