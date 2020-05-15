//
//  Solution111.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/12.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution111_hpp
#define Solution111_hpp

#include <stdio.h>
#include "Leetcode_C.h"

/**
 给定一个二叉树，找出其最小深度。

 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

 说明: 叶子节点是指没有子节点的节点。
 */

class Solution111 {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) return 1;
        int res = INT_MAX;
        if (root->left != NULL) {
            res = min(minDepth(root->left), res);
        }
        if (root->right != NULL) {
            res = min(minDepth(root->right), res);
        }
        return res+1;
    }
    
    int minDepth1(TreeNode* root) {
        // 遍历
        
        vector<int> demo{1, 2, 3, 5, 4};
        sort(demo.begin(), demo.end());
        
        return 0;
    }
    

};

#endif /* Solution111_hpp */
