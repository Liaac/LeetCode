/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    void traverse(TreeNode* node, int sum, vector<int>& path, vector<vector<int>>& res) {
        if (node == nullptr) return;
        path.push_back(node->val);
        if (!node->left && !node->right && sum == node->val) {
            res.push_back(path);
        } else {
            traverse(node->left, sum - node->val, path, res);
            traverse(node->right, sum - node->val, path, res);
        }
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        traverse(root, targetSum, path, res);
        return res;
    }
};
// @lc code=end

