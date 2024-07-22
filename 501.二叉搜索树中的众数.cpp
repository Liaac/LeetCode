/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int _curVal = 0;
    int _curCount = 0;
    int _maxCount = 0;
    vector<int> _res;

    void traverse(TreeNode* root) {
        if (root == nullptr) return;
        traverse(root->left);
        if (root->val == _curVal) {
            ++_curCount;
        } else {
            _curCount = 1;
            _curVal = root->val;
        }

        if (_curCount == _maxCount) {
            _res.push_back(_curVal);
        } else if (_curCount > _maxCount) {
            _res.clear();
            _maxCount = _curCount;
            _res.push_back(_curVal);
        }
        traverse(root->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        return _res;
    }
};
// @lc code=end

