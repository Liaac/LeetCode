/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int val) : val(val), next(nullptr) {}
    };

    MyLinkedList() {
        _size = 0;
        _dummyNode = new ListNode(0);
    }
    
    int get(int index) {
        if (index >= _size) {
            return -1;
        }
        ListNode* cur = _dummyNode->next;
        while (index-- > 0) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* newHead = new ListNode(val);
        newHead->next = _dummyNode->next;
        _dummyNode->next = newHead;
        ++_size;
    }
    
    void addAtTail(int val) {
        ListNode* newTail = new ListNode(val);
        ListNode* cur = _dummyNode;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = newTail;
        ++_size;
    }
    
    void addAtIndex(int index, int val) {
        if (index > _size) return;
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyNode;
        while (index-- > 0) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        ++_size;
    }
    
    void deleteAtIndex(int index) {
        if (index >= _size) return;
        ListNode* cur = _dummyNode;
        while (index-- > 0) {
            cur = cur->next;
        }
        ListNode* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        --_size;
    }

private:
    int _size;
    ListNode* _dummyNode;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

