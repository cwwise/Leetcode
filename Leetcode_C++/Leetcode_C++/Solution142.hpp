//
//  Solution142.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/30.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution142_hpp
#define Solution142_hpp

#include <stdio.h>
#include "Leetcode_C.h"

class Solution142 {
public:
    ListNode *detectCycle(ListNode *head) {
        // 如果没环
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                break;
            }
        }
        // 这个时候找到环节点。
        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
    
    void test() {
        // [3,2,0,-4]
        ListNode *node1 = new ListNode(3);
        ListNode *node2 = new ListNode(2);
        ListNode *node3 = new ListNode(5);
        ListNode *node4 = new ListNode(-4);

        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node2;

    }
};

#endif /* Solution142_hpp */
