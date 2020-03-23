//
//  Leetcode_C.h
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/23.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Leetcode_C_h
#define Leetcode_C_h

#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

namespace NodeTestHelper {

void printNodeList(ListNode *head) {
    ListNode *p = head;
    while (p != nullptr && p->next != nullptr) {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << p->val << endl;
}

void printNodeList(string name, ListNode *head) {
    ListNode *p = head;
    cout << name << ":" << endl;
    while (p != nullptr && p->next != nullptr) {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << p->val << endl;
}

ListNode *createNode(vector<int> arr) {
    ListNode *head = NULL;
    ListNode *cur = NULL;
    for (int i = 0; i < arr.size(); i ++) {
        ListNode *p = new ListNode(arr[i]);
        if (head == NULL) {
            head = p;
        } else {
            cur->next = p;
        }
        cur = p;
    }
    return head;
}

}



#endif /* Leetcode_C_h */
