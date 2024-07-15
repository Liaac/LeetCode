/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
// #include <queue>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;
// #endif

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> curLevel;
            while (size-- > 0) {
                TreeNode* cur = q.front();
                q.pop();
                curLevel.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            res.push_back(curLevel);
        }
        return res;
    }
};
// @lc code=end

