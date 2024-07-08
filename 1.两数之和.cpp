/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
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
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); ++i) {
            int dif = target - nums[i];
            if (numMap.count(dif)) {
                int index = numMap.at(dif);
                return {index, i};
            } else {
                numMap.insert(pair<int, int>(nums[i], i));
            }
        }
        return {};
    } 
};
// @lc code=end

