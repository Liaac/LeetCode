/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
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
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> bucket1;
        int res = 0;
        for (int i : nums1) {
            for (int j : nums2) {
                ++bucket1[i + j];
            }
        }
        for (int i : nums3) {
            for (int j : nums4) {
                int target = 0 - (i + j);
                auto it = bucket1.find(target);
                if (it != bucket1.end()) {
                    res += it->second;
                }
            }
        }
        return res;
    }
};
// @lc code=end

