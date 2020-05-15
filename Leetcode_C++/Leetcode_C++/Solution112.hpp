//
//  Solution112.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/16.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution112_hpp
#define Solution112_hpp

#include <stdio.h>
#include "Leetcode_C.h"

class Solution112 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, 0, sum);
        stack<int> s;
    }
    
    //
    bool dfs(TreeNode *node, int cur, int sum) {
        if (node == NULL) {
            return false;
        }
        cur = cur + node->val;
        if (node->left == NULL && node->right == NULL) {
            return cur == sum;
        } else {
            return dfs(node->left, cur, sum) || dfs(node->right, cur, sum);
        }
    }
    
    
    void test() {
        
    }
};

#endif /* Solution112_hpp */
