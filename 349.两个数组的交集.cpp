/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> setNums1(nums1.begin(), nums1.end());
        unordered_set<int> res;
        for (int num : nums2) {
            if (setNums1.count(num)) {
                res.insert(num);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};
// @lc code=end

