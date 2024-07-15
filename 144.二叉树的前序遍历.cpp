/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
// #include <unordered_map>
// #include <unordered_set>
// #include <stack>
// using namespace std;
// #endif

class Solution {
// private:
//     void traverse(TreeNode* root, vector<int>& res) {
//         if (root == nullptr) return;
//         res.push_back(root->val);
//         traverse(root->left, res);
//         traverse(root->right, res);
//     } 

public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            res.push_back(cur->val);
            if (cur->right) stk.push(cur->right);
            if (cur->left) stk.push(cur->left);
        }
        return res;
    }
};
// @lc code=end

