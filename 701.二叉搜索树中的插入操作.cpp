/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if (root == nullptr) {
            return node;
        }
        TreeNode* cur = root;
        TreeNode* pre = root;
        while (cur) {
            pre = cur;
            if (cur->val > val) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        if (pre->val > val) {
            pre->left = node;
        } else {
            pre->right = node;
        }
        return root;
    }
};
// @lc code=end

