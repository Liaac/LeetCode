/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    unordered_map<int, int> _indexMap;

    TreeNode* traverse(vector<int>& inorder, vector<int>& postorder,
                       int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }
        int rootVal = postorder[postEnd];
        int rootIndex = _indexMap[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        int leftTreeLength = rootIndex - inStart;
        root->left = traverse(inorder, postorder,
                              inStart, rootIndex - 1,
                              postStart, postStart + leftTreeLength - 1);
        root->right = traverse(inorder, postorder,
                               rootIndex + 1, inEnd,
                               postStart + leftTreeLength, postEnd - 1);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            _indexMap[inorder[i]] = i;
        }
        return traverse(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
// @lc code=end

