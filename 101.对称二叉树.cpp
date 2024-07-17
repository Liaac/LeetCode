/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
// #ifndef ONLINE_JUDGE
// #include "include/leetcode_structures.h"
// #include <vector>
// #include <string>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;
// #endif

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> stk;
        stk.push(root);
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* left = stk.top(); stk.pop();
            TreeNode* right = stk.top(); stk.pop();
            if (!left && !right) continue;
            if (!left || !right || left->val != right->val) return false;
            stk.push(left->left);
            stk.push(right->right);
            stk.push(left->right);
            stk.push(right->left);
        }
        return true;
    }
};
// @lc code=end

