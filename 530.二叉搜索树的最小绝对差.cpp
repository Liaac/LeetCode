/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
// #include <climits>
// using namespace std;

class Solution {
private:
    TreeNode* _pre = nullptr;
    int _min = INT_MAX;

    void traverse(TreeNode* root) {
        if (root == nullptr) return;
        traverse(root->left);
        if (_pre != nullptr) {
            _min = min(_min, root->val - _pre->val);
        }
        _pre = root;
        traverse(root->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        traverse(root);
        return _min;
    }
};
// @lc code=end

