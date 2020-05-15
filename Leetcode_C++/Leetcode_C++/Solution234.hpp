//
//  Solution234.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/12.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution234_hpp
#define Solution234_hpp

#include <stdio.h>
#include "Leetcode_C.h"
/**
 请判断一个链表是否为回文链表。

 */
class Solution234 {
public:
    ListNode *left;
    bool isPalindrome(ListNode* head) {
        left = head;
        
        //
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (fast != NULL) {
            slow = slow->next;
        }
        
        ListNode *left = head;
        ListNode *right = traverse1(slow);
        
        while (right != NULL) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
        
    ListNode *traverse1(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *cur = head;
        while (cur != NULL) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    
    bool traverse(ListNode* right) {
        if (right == NULL) {
            return true;
        }
        bool res = traverse(right->next);
        res = res && (right->val == left->val);
        left = left->next;
        return res;
    }
    
    void test() {
        ListNode *head = NodeTestHelper::createNode({1, 2});
        cout << isPalindrome(head);
    }
};

#endif /* Solution234_hpp */
