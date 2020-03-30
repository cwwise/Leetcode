//
//  Solution62.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/30.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution62_hpp
#define Solution62_hpp

#include <stdio.h>

class Solution62 {
public:
    int func(int n, int m) {
        if (n == 1) {
            return 0;
        }
        int x = func(n - 1, m);
        return (m + x) % n;
    }
    
    int lastRemaining(int n, int m) {
        return func(n, m);
    }
    
    void test() {
        cout << lastRemaining(5, 3) << endl;
    }
};

#endif /* Solution62_hpp */
