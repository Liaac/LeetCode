/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int _maxDepth = -1;
    int _leftValue;

    void traverse(TreeNode* node, int depth) {
        if (node == nullptr) return;
        if (depth > _maxDepth) {
            _maxDepth = depth;
            _leftValue = node->val;
        }
        if (node->left) {
            traverse(node->left, depth + 1);
        }
        if (node->right) {
            traverse(node->right, depth + 1);
        }
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        traverse(root, 0);
        return _leftValue;
    }
};
// @lc code=end

