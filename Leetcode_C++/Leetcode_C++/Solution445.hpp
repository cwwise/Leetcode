//
//  Solution445.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/14.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution445_hpp
#define Solution445_hpp

#include <stdio.h>
#include "Leetcode_C.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution445 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        stack<int> s1, s2;
        while (l1 != NULL) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        
        while (l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int carry = 0;
        ListNode* ans = nullptr;
        while (!s1.empty() || !s2.empty() || carry != 0) {

            int a = 0;
            if (!s1.empty()) {
                a = s1.top();
                s1.pop();
            }
            
            int b = 0;
            if (!s2.empty()) {
                b = s2.top();
                s2.pop();
            }
            
            int cur = a + b + carry;
            carry = cur / 10;

            auto p = new ListNode(cur%10);
            p -> next = ans;
            ans = p;
        }
        return ans;
    }
    
    void test() {
        
    }
};

#endif /* Solution445_hpp */
