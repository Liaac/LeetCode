/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
private:
    bool traverse(TreeNode* root, long long min, long long max) {
        if (root == nullptr) return true;
        if (root->val <= min || root->val >= max) return false;
        return traverse(root->left, min, root->val) && 
               traverse(root->right, root->val, max);
    }

public:
    bool isValidBST(TreeNode* root) {
        return traverse(root, LONG_MIN, LONG_MAX);
    }
};
// @lc code=end

