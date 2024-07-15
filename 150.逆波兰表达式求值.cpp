/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
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
    int evalRPN(vector<string>& tokens) {
        stack<int> numStack;
        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int second = numStack.top();
                numStack.pop();
                int first = numStack.top();
                numStack.pop();
                if (s == "+") numStack.push(first + second);
                else if (s == "-") numStack.push(first - second);
                else if (s == "*") numStack.push(first * second);
                else if (s == "/") numStack.push(first / second);
            } else {
                numStack.push(stoi(s));
            }
        }
        return numStack.top();
    }
};
// @lc code=end

