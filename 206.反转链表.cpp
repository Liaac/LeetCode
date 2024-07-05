/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// #ifndef ONLINE_JUDGE
// #include "include/leetcode_structures.h"
// #include <vector>
// #include <string>
// #include <unordered_map>
// #endif

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);
    }

    ListNode* reverse(ListNode* pre, ListNode* head) {
        if (!head) return pre;
        ListNode* tmp = head->next;
        head->next = pre;
        return reverse(head, tmp);
    }
};
// @lc code=end

