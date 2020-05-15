//
//  Solution236.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/10.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution236_hpp
#define Solution236_hpp

#include <stdio.h>
#include "Leetcode_C.h"

class Solution236 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (!left) return left;
        if (!right) return right;
        return root;
    }
};

#endif /* Solution236_hpp */
