/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
// #include "include/leetcode_structures.h"
// #include <vector>
// #include <string>
// #include <unordered_map>
// using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int record[26] = {};
        for (char c : s) {
            ++record[c - 'a'];
        }
        for (char c : t) {
            if (--record[c - 'a'] < 0) {
                return false;
            }
        }
        // for (int i = 0; i < 26; ++i) {
        //     if (record[i] != 0) {
        //         return false;
        //     }
        // }
        return true;
    }
};
// @lc code=end

