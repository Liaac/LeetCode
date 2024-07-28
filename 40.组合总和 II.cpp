/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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

    void backtrack(vector<int>& candidates, int start, int sum, int target) {
        if (sum == target) {
            _res.push_back(_path);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] + sum > target) return;
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            _path.push_back(candidates[i]);
            backtrack(candidates, i + 1, sum + candidates[i], target);
            _path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, 0, target);
        return _res;
    }
};
// @lc code=end


