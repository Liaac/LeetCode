/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// #include "include/leetcode_structures.h"
// #include <vector>
// #include <string>
// #include <stack>
// #include <queue>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        stack<TreeNode*> stk;
        stk.push(root);
        int res = 0;
        while (!stk.empty()) {
            TreeNode* cur = stk.top(); stk.pop();
            // 若左节点不为nullptr且为叶子节点
            if (cur->left && !cur->left->left && !cur->left->right) {
                res += cur->left->val;
            }
            if (cur->left) stk.push(cur->left);
            if (cur->right) stk.push(cur->right);
        }
        return res;
    }
};
// @lc code=end

