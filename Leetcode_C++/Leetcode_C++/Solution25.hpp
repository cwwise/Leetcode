//
//  Solution25.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/16.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution25_hpp
#define Solution25_hpp

#include <stdio.h>
#include "Leetcode_C.h"

class Solution25 {
public:
    
    pair<ListNode *, ListNode *> reverse(ListNode* head, ListNode *tail) {
        ListNode *cur = head;
        ListNode *pre = NULL;
        while (cur != NULL) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return {head, head};
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newHead = new ListNode(0);
        
        
        
        
        
        return newHead;
    }
    
    void test() {
        
    }
};

#endif /* Solution25_hpp */
