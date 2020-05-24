//
//  Solution145.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/23.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution145_hpp
#define Solution145_hpp

#include <stdio.h>
#include "Leetcode_C.h"

class Solution145 {
public:
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nums;
        stack<TreeNode *>stack;
        if (root) stack.push(root);
        while (!stack.empty()) {
            TreeNode *node = stack.top();
            stack.pop();
            if (node != nullptr) {
                stack.push(node);
                stack.push(nullptr);
                if (node->right) stack.push(node->right);
                if (node->left) stack.push(node->left);
            } else {
                nums.push_back(stack.top()->val);
                stack.pop();
            }
        }
        return nums;
    }
};

#endif /* Solution145_hpp */
