/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (p->val > q->val) return lowestCommonAncestor(root, q, p);
        if ((root->val >= p->val && root->val <= q->val)) {
            return root;
        } else if (root->val < p->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return lowestCommonAncestor(root->left, p, q);
        }
    }
};
// @lc code=end

