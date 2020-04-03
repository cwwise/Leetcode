//
//  Solution21.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/31.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution21_hpp
#define Solution21_hpp

#include <stdio.h>
#include "Leetcode_C.h"

class Solution21 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        
        ListNode *p = l1;
        ListNode *q = l2;
        
        ListNode *cur = head;
        while (p != NULL && q != NULL) {
            if (p->val < q->val) {
                cur->next = p;
                p = p->next;
            } else {
                cur->next = q;
                q = q->next;
            }
            cur = cur->next;
        }
        
        cur->next = (p != NULL) ? p : q;
        return head->next;

    }
    
    void test() {
        ListNode *p1 = NodeTestHelper::createNode(vector<int>{1, 2, 10});
        ListNode *p2 = NodeTestHelper::createNode(vector<int>{3, 4, 5});
        
        NodeTestHelper::printNodeList(mergeTwoLists(p1, p2));
    }
};

#endif /* Solution21_hpp */
