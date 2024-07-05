/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res(nums.size(), 0);
        int cur = nums.size() - 1;
        while (left <= right) {
            int left_square = nums[left] * nums[left];
            int right_square = nums[right] * nums[right];
            if (left_square < right_square) {
                res[cur--] = right_square;
                --right; 
            } else {
                res[cur--] = left_square;
                ++left;
            }
        }
        return res;
    }
};
// @lc code=end

