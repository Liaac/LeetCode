/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
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

    void backtrack(int start, int sum, int n, int k) {
        if (_path.size() == k) {
            if (sum == n) _res.push_back(_path);
            return;
        }
        for (int i = start; i <= 9; ++i) {
            _path.push_back(i);
            backtrack(i + 1, sum + i, n, k);
            _path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(1, 0, n, k);
        return _res;
    }
};
// @lc code=end

