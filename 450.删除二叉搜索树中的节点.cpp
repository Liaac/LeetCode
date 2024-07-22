/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (!root->left) {
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            } else if (!root->right) {
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            } else {
                TreeNode* cur = root->right;
                while (cur->left) {
                    cur = cur->left;
                }
                cur->left = root->left;
                cur = root->right;
                delete root;
                return cur;
            }
        }
        return root;
    }
};
// @lc code=end

