//
//  Solution141.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/30.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution141_hpp
#define Solution141_hpp

#include <stdio.h>
#include "Leetcode_C.h"

class Solution141 {
public:
    bool hasCycle(ListNode *head) {
        
        if (head == NULL || head->next == NULL) {
            return false;
        }
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while (slow != fast) {
            if (fast == NULL || fast->next == NULL) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
    
    void test() {
        // [3,2,0,-4]
        ListNode *node1 = new ListNode(3);
        ListNode *node2 = new ListNode(2);
        ListNode *node3 = new ListNode(0);
        ListNode *node4 = new ListNode(-4);

        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node2;

        cout << hasCycle(node1) << endl;
    }
};

#endif /* Solution141_hpp */
