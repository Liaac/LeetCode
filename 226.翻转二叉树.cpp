/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
private:
    void reverse(TreeNode* root) {
        if (root == nullptr) return;
        swap(root->left, root->right);
        reverse(root->left);
        reverse(root->right);
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        reverse(root);
        return root;
    }
};
// @lc code=end

