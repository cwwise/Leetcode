//
//  Solution102.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/13.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution102_hpp
#define Solution102_hpp

#include <stdio.h>
#include "Leetcode_C.h"

class Solution102 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 队列
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            vector<int> list;
            size_t n = queue.size();
            while (n > 0) {
                TreeNode *node = queue.front();
                queue.pop();
                list.push_back(node->val);
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
                n --;
            }
            res.push_back(list);
        }
        return res;
    }
    
    //
};

#endif /* Solution102_hpp */
