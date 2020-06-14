//
//  Solution889.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/6/11.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution889_hpp
#define Solution889_hpp

#include <stdio.h>
#include "Leetcode_C.h"

class Solution889 {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        if (n == 0) return nullptr;
        return buildTree(pre, 0, n - 1, post, 0, n - 1);
    }

    TreeNode *buildTree(vector<int> pre, int preLeft, int preRight,
                        vector<int> post, int postLeft, int postRight) {
        if (preLeft > preRight || postLeft > postRight) return nullptr;
        TreeNode *node = new TreeNode(post[postRight]);
        if (preRight == preLeft) {
            return node;
        }
        // 后序遍历的最后一个节点就是根节点
        int pivot = post[postRight - 1];
        // 找到前序中的位置
        int pivotIndex = preLeft;
        while (pre[pivotIndex] != pivot) {
            pivotIndex ++;
        }
        int right_Length = preRight - pivotIndex + 1;
        node->left = buildTree(pre, preLeft + 1, pivotIndex - 1,
                               post, postLeft, postRight - right_Length - 1);
        //
        node->right = buildTree(pre, pivotIndex, preRight,
                                post, postRight - right_Length, postRight - 1);
        return node;
    }
    
    void test() {
        vector<int> pre = {1,2,4,5,3,6,7};
        vector<int> post = {4,5,2,6,7,3,1};
        constructFromPrePost(pre, post);
    }

};

#endif /* Solution889_hpp */
