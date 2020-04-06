//
//  Solution866.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/2.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution866_hpp
#define Solution866_hpp

#include <stdio.h>
#include "Leetcode_C.h"

class Solution866 {
public:
    int primePalindrome(int N) {
   
        while (true) {
            if (prime(N) && palindrome(N)) {
                break;
            }
            N ++;
            if (10000000 < N && N < 100000000)
                N = 100000000;
        }
        return N;
    }
    
    bool prime(int x) {
        if (x < 2) {
            return false;
        }
        int k = sqrt(x);
        int i = 2;
        for (; i <= k; i ++) {
            if (x % i == 0) {
                break;
            }
        }
        return i > k;
    }
    
    bool palindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int value = 0;
        while (x > value) {
            value = x % 10 + value*10;
            x /= 10;
        }
        return x == value || value / 10 == x;
    }
    
    
    void test() {
        for (int i = 9989900; i < 9989901; i += 10) {
            cout << i  << "-> " << primePalindrome(i) << endl;
        }

    }
};

#endif /* Solution866_hpp */
