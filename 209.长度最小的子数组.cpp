/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int left = 0;
        int sum = 0;
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while (sum >= target) {
                int len = right - left + 1;
                res = res > len ? len : res;
                sum -= nums[left++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end

