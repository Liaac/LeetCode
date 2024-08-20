/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
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
    vector<string> _path;
    bool _found = false;

    void backtrack(vector<vector<string>>& tickets, string current, vector<bool>& used) {
        if (_path.size() == tickets.size() + 1) {
            _found = true;
            return;
        }

        for (int i = 0; i < tickets.size(); ++i) {
            if (tickets[i][0] == current && !used[i]) {
                used[i] = true;
                _path.push_back(tickets[i][1]);
                backtrack(tickets, tickets[i][1], used);
                if (_found) return;
                used[i] = false;
                _path.pop_back();
            }
        }
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        vector<bool> used(tickets.size(), false);
        _path.push_back("JFK");
        backtrack(tickets, "JFK", used);
        return _path;
    }
};
// @lc code=end

