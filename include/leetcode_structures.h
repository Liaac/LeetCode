// leetcode_structures.h
#ifndef LEETCODE_STRUCTURES_H
#define LEETCODE_STRUCTURES_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 可以添加其他LeetCode常用的结构定义

#endif // LEETCODE_STRUCTURES_H