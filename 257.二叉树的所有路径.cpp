/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) return res;
        stack<TreeNode*> nodeStk;
        stack<string> pathStk;
        nodeStk.push(root);
        pathStk.push(to_string(root->val));
        while (!nodeStk.empty()) {
            TreeNode* cur = nodeStk.top(); nodeStk.pop();
            string path = pathStk.top(); pathStk.pop();
            if (!cur->left && !cur->right) {
                res.push_back(path);
                continue;
            }
            if (cur->left) {
                nodeStk.push(cur->left);
                pathStk.push(path + "->" + to_string(cur->left->val));
            }
            if (cur->right) {
                nodeStk.push(cur->right);
                pathStk.push(path + "->" + to_string(cur->right->val));
            }
        }
        return res;
    }
};
// @lc code=end

