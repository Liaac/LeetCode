/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */
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
    vector<int> _path;

    void backtrack(vector<int>& nums, int start) {
        if (_path.size() >= 2) {
            _res.push_back(_path);
        }
        if (start >= nums.size()) return;

        unordered_set<int> used;
        for (int i = start; i < nums.size(); ++i) {
            if (!_path.empty() && nums[i] < _path.back()) continue;
            if (used.count(nums[i])) continue;
            _path.push_back(nums[i]);
            used.insert(nums[i]);
            backtrack(nums, i + 1);
            _path.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return _res;
    }
};
// @lc code=end

