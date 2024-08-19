/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
// #include "leetcode_structures.h"
// #include <vector>
// #include <unordered_map>
// #include <unordered_set>
// #include <string>
// #include <algorithm>
// using namespace std;

// @lc code=start
class Solution {
private:
    vector<vector<int>> _res;

    void backtrack(vector<int>& nums, int start) {
        if (start >= nums.size()) {
            _res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1);
            swap(nums[start], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return _res;
    }
};
// @lc code=end

