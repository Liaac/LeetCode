/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int round = n / 2;
        int len = n - 1;
        int num = 1;
        for (int cur = 0; cur < round; cur++) {
            int i = cur;
            int j = cur;
            // 向右
            while (j < len - cur) {
                res[i][j++] = num++;
            }
            // 向下
            while (i < len - cur) {
                res[i++][j] = num++;
            }
            // 向左
            while (j > cur) {
                res[i][j--] = num++;
            }
            // 向上
            while (i > cur) {
                res[i--][j] = num++;
            }
        }
        if (n % 2 == 1) {
            res[n / 2][n / 2] = num;
        }
        return res;
    }
};
// @lc code=end

