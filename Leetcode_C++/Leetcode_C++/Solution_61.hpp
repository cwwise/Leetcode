//
//  Solution_61.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/9.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution_61_hpp
#define Solution_61_hpp

#include <stdio.h>

class Solution_61 {
public:
    bool isStraight(vector<int>& nums) {
        set<int> set;
        int max_value = 0;
        int min_value = 14;
        
        for (int num: nums) {
            if (num == 0) continue;
            max_value = max(max_value, num);
            min_value = min(min_value, num);
            
            auto [iterator, success] = set.insert(num);
            if (!success) return false;
        }
        return max_value - min_value < 5;
    }
    
    void test() {
        vector<int> demo{4,7,5,9,2};
        isStraight(demo);
    }
};

#endif /* Solution_61_hpp */
