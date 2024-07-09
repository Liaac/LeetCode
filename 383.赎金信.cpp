/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
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
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;
        int record[26] = {};
        for (char c : magazine) {
            ++record[c - 'a'];
        }
        for (char c : ransomNote) {
            if (--record[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

