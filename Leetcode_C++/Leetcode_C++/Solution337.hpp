//
//  Solution337.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/13.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution337_hpp
#define Solution337_hpp

#include <stdio.h>

class Solution337 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
    int rob(TreeNode* root) {
        vector<int> res = dp(root);
        return max(res[0], res[1]);
    }
    
    vector<int> dp(TreeNode* root) {
        if (root == NULL) {
            return vector<int>{0, 0};
        }
        
        vector<int> left = dp(root->left);
        vector<int> right = dp(root->right);
        
        int rob = root->val + left[0] + right[0];
        int not_rob = max(left[0], left[1]) + max(right[0], right[1]);
        return vector<int>{not_rob, rob};
    }
    
};

#endif /* Solution337_hpp */
