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
    
    pair<ListNode *, ListNode *> reverseNode(ListNode* head, ListNode *tail) {
        ListNode *prev = tail->next;
        ListNode *p = head;
        
        while (prev != tail) {
            ListNode *next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        return {tail, head};
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        
        ListNode *cur = head;
        ListNode *pre = newHead;
        
        while (cur) {
            
            ListNode* nextLast = pre;
            // 找到对应节点
            for (int i = 0; i < k; i ++) {
                nextLast = nextLast->next;
                if (!nextLast) {
                    return newHead->next;
                }
            }
            ListNode* nex = nextLast->next;
            auto [start, end] = reverseNode(cur, nextLast);
            pre->next = start;
            end->next = nex;
            
            pre = end;
            cur = nex;
        }
        return newHead->next;
    }
    
    void test() {
        
    }
};

#endif /* Solution25_hpp */
