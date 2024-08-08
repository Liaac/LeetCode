/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
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
    vector<vector<int>> _res;
    vector<int> _path;
    void backtrack(vector<int>& nums, int start) {
        _res.push_back(_path);
        if (start == nums.size()) return;
        for (int i = start; i < nums.size(); ++i) {
            _path.push_back(nums[i]);
            backtrack(nums, i + 1);
            _path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return _res;
    }
};
// @lc code=end

