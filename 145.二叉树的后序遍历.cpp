/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            res.push_back(cur->val);
            if (cur->left) stk.push(cur->left);
            if (cur->right) stk.push(cur->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

