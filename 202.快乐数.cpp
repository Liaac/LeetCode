/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
// #include "include/leetcode_structures.h"
// #include <vector>
// #include <string>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;

// @lc code=start
class Solution {
public:
    int getSum(int n) {
        int cur = 0;
        while (n != 0) {
            int tmp = n % 10;
            cur += tmp * tmp;
            n /= 10;
        }
        return cur;
    }
    bool isHappy(int n) {
        unordered_set<int> sum;
        while (true) {
            int cur = getSum(n);
            if (cur == 1) {
                return true;
            }
            if (sum.count(cur) == 1) {
                return false;
            } else {
                sum.insert(cur);
            }
            n = cur;
        }
    }
};
// @lc code=end

