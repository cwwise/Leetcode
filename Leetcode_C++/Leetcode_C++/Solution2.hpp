//
//  Solution2.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/23.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution2_hpp
#define Solution2_hpp

#include <stdio.h>
#include "Leetcode_C.h"

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
        ListNode *dummyHead = new ListNode(0);
        ListNode *p = l1, *q = l2, *curr = dummyHead;
        int carry = 0;
        while (p != nullptr || q != nullptr) {
            int x = (p != nullptr) ? p->val : 0;
            int y = (q != nullptr) ? q->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (p != nullptr) p = p->next;
            if (q != nullptr) q = q->next;
        }
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }
        return dummyHead->next;
    }
    
    void test() {
        ListNode *head1 = NodeTestHelper::createNode(vector<int>{1, 2, 3});
        ListNode *head2 = NodeTestHelper::createNode(vector<int>{1, 2, 8});
        NodeTestHelper::printNodeList(addTwoNumbers(head1, head2));
    }
};

#endif /* Solution2_hpp */
