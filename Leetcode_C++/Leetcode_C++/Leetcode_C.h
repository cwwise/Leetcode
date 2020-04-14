//
//  Leetcode_C.h
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/23.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Leetcode_C_h
#define Leetcode_C_h

#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    ListNode *head = new ListNode(0);
    ListNode *cur = head;
    for (int i = 0; i < arr.size(); i ++) {
        ListNode *p = new ListNode(arr[i]);
        cur->next = p;
        cur = p;
    }
    return head->next;
}

}



#endif /* Leetcode_C_h */
