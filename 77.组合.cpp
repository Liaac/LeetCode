/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
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

    void backtrack(int start, int n, int k) {
        if (_path.size() == k) {
            _res.push_back(_path);
            return;
        }
        for (int i = start; i <= n; ++i) {
            _path.push_back(i);
            backtrack(i + 1, n, k);
            _path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return _res;
    }
};
// @lc code=end

