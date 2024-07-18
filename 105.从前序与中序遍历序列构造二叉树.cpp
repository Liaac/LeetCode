/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

    TreeNode* traverse(vector<int>& preorder, vector<int>& inorder, 
                       int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;
        int rootVal = preorder[preStart];
        int rootIndex = _indexMap[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        int leftTreeLength = rootIndex - inStart;
        root->left = traverse(preorder, inorder, 
                              preStart + 1, preStart + leftTreeLength,
                              inStart, rootIndex - 1);
        root->right = traverse(preorder, inorder,
                               preStart + leftTreeLength + 1, preEnd,
                               rootIndex + 1, inEnd);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            _indexMap[inorder[i]] = i;
        }
        return traverse(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
// @lc code=end

