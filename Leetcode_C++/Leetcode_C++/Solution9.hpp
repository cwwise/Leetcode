//
//  Solution9.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/2.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution9_hpp
#define Solution9_hpp

#include <stdio.h>
#include "Leetcode_C.h"

class Solution9 {
public:
    //
    bool isPalindrome1(int x) {
        
        if (x < 0) {
            return true;
        }
        
        // 先计算多少位数据
        int div = 1;
        while (x / div >= 10) {
            div *= 10;
        }
        
        //
        while (x > 0) {
            int a = x / div;
            int b = x % 10;
            if (a != b) {
                return false;
            }
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
    
    bool isPalindrome(int x) {
        
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        
        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        return revertedNumber == x || revertedNumber / 10 == x;
    }
    
    void test() {
        cout << isPalindrome(1001) << endl;
    }
};


#endif /* Solution9_hpp */
