/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
// #ifndef ONLINE_JUDGE
// #include "include/leetcode_structures.h"
// #include <vector>
// #include <string>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;
// #endif

// @lc code=start
class Solution {
private:
    void reverse(string& s, int start, int end) {
        while (start < end) {
            swap(s[start++], s[end--]); 
        }
    }

public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            if (i + k > s.size()) {
                reverse(s, i, s.size() - 1);
                return s;
            }
            reverse(s, i, i + k - 1);
        }
        return s;
    }
};
// @lc code=end

