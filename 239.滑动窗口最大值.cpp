/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
// #ifndef ONLINE_JUDGE
// #include "include/leetcode_structures.h"
// #include <vector>
// #include <string>
// #include <deque>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;
// #endif

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
// @lc code=end

