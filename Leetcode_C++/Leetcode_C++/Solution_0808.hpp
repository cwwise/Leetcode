//
//  Solution_0808.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/21.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution_0808_hpp
#define Solution_0808_hpp

#include <stdio.h>

class Solution0808 {
public:
    vector<string> res;
    vector<string> permutation(string s) {
        if (s.length() == 0) return res;
        vector<char> nums;
        for (char c: s) {
            nums.push_back(c);
        }

        sort(nums.begin(), nums.end());
        vector<bool> used(s.length());
        string path;
        backtack(nums, 0, used, path);
        return res;
    }

    void backtack(vector<char> nums, int start,
                  vector<bool> &used, string &path) {
        if (start == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i ++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && used[i-1]) continue;

            used[i] = true;
            path.push_back(nums[i]);
            backtack(nums, start+1, used, path);
            used[i] = false;
            path.pop_back();
        }

    }
    
    void test() {
        permutation("ab");
    }
};

#endif /* Solution_0808_hpp */
