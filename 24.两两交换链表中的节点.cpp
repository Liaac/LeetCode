/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
//  #ifndef ONLINE_JUDGE
//  #include "include/leetcode_structures.h"
//  #include <vector>
//  #include <string>
//  #include <unordered_map>
//  #endif

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = dummy->next;
        while (cur && cur->next) {
            ListNode* front = cur;
            ListNode* back = cur->next;
            cur = back->next;
            pre->next = back;
            back->next = front;
            front->next = cur;
            pre = front;
        }
        return dummy->next;
    }
};
// @lc code=end

