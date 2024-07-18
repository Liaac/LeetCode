/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    int _target;

    bool traverse(TreeNode* node, int sum) {
        if (node == nullptr) return false;
        sum += node->val;
        if (!node->left && !node->right && sum == _target) {
            return true;
        }
        bool leftHas = traverse(node->left, sum);
        bool rightHas = traverse(node->right, sum);
        return leftHas || rightHas;
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        _target = targetSum;
        return traverse(root, 0);
    }
};
// @lc code=end

