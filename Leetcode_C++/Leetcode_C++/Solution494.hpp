//
//  Solution494.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/31.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution494_hpp
#define Solution494_hpp

#include "Leetcode_C.h"
#include <stdio.h>

/*
 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
 
 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
 
 示例 1:
 
 输入: nums: [1, 1, 1, 1, 1], S: 3
 输出: 5
 解释:
 
 -1+1+1+1+1 = 3
 +1-1+1+1+1 = 3
 +1+1-1+1+1 = 3
 +1+1+1-1+1 = 3
 +1+1+1+1-1 = 3
 
 一共有5种方法让最终目标和为3。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/target-sum
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution494 {
public:
    int count = 0;
    void calculate(vector<int>& nums, int i, int sum, int S) {
        if (i == nums.size()) {
            if (sum == S) {
                count ++;
            }
        } else {
            calculate(nums, i + 1, sum - nums[i], S);
            calculate(nums, i + 1, sum + nums[i], S);
        }
    }
    
    
    int dfs(vector<int> &nums, uint target, int left) {
        if (target == 0 && left == nums.size()) return 1;
        if (left >= nums.size()) return 0;
        int ans = 0;
        ans += dfs(nums, target - nums[left], left + 1);
        ans += dfs(nums, target + nums[left], left + 1);
        return ans;
    }
    
    int dfs(vector<int>& nums, int target, int i) {
        
        if (target == 0 && i == nums.size()) {
            return 1;
        }
        
        if (i >= nums.size()) {
            return 0;
        }
        
        int ans = 0;
        ans += dfs(nums, target - nums[i], i + 1);
        ans += dfs(nums, target + nums[i], i + 1);
        return ans;
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        //        calculate(nums, 0, 0, S);
        return dfs(nums, S, 0);
    }
    
    void test() {
        vector<int> test = vector<int>{1, 1, 1, 1, 1};
        cout << findTargetSumWays(test, 3) << endl;
    }
};


#endif /* Solution494_hpp */
