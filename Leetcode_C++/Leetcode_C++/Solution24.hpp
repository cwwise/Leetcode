//
//  Solution24.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/30.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution24_hpp
#define Solution24_hpp

#include <stdio.h>
#include "Leetcode_C.h"

class Solution24 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = NULL;
        ListNode *pre = head;
        while (pre != NULL) {
            ListNode *next = pre->next;
            pre->next = cur;
            cur = pre;
            pre = next;
        }
        return cur;
    }
    
    ListNode* reverseList1(ListNode* head) {
        
        if (head == NULL) {
            return NULL;
        }
        
        ListNode *cur = head;
        while (head->next != NULL) {
            // 1->2->3
            ListNode *node = head->next->next;
            
            head->next->next = cur;
            cur = head->next;
            head->next = node;
        }
        
        return cur;
    }
    
    void test() {
        ListNode *node1 = new ListNode(3);
        ListNode *node2 = new ListNode(2);
        ListNode *node3 = new ListNode(0);
        ListNode *node4 = new ListNode(-4);

        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        
        NodeTestHelper::printNodeList(node1);
        
        
        NodeTestHelper::printNodeList(reverseList1(node1));
    }
};

#endif /* Solution24_hpp */
