//
//  main.cpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/23.
//  Copyright © 2020 chenwei. All rights reserved.
//

#include <iostream>
#include "Leetcode_C.h"

#include "Solution2.hpp"
#include "Solution5.hpp"
#include "Solution8.hpp"
#include "Solution9.hpp"
#include "Solution17.hpp"
#include "Solution21.hpp"
#include "Solution24.hpp"
#include "Solution46.hpp"
#include "Solution51.hpp"
#include "Solution61.hpp"
#include "Solution62.hpp"
#include "Solution70.hpp"
#include "Solution72.hpp"
#include "Solution102.hpp"
#include "Solution120.hpp"
#include "Solution121.hpp"
#include "Solution122.hpp"
#include "Solution123.hpp"
#include "Solution141.hpp"
#include "Solution142.hpp"
#include "Solution152.hpp"
#include "Solution188.hpp"
#include "Solution198.hpp"
#include "Solution200.hpp"
#include "Solution203.hpp"
#include "Solution289.hpp"
#include "Solution309.hpp"
#include "Solution322.hpp"
#include "Solution328.hpp"
#include "Solution337.hpp"
#include "Solution355.hpp"
#include "Solution445.hpp"
#include "Solution494.hpp"
#include "Solution516.hpp"
#include "Solution542.hpp"
#include "Solution674.hpp"
#include "Solution714.hpp"
#include "Solution866.hpp"
#include "Solution867.hpp"
#include "Solution912.hpp"
#include "Solution1143.hpp"
#include "Solution1162.hpp"
#include "Solution_1603.hpp"
#include "Solution_0811.hpp"
#include "MyQueue.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
//    Solution2().test();
//    Solution674().test();
    
//    string s = "12";
//    cout << s.substr(0, 3);
    set<int> demo;
    map<string, string> direct;
    direct.insert(make_pair("1", "2"));
    
    auto it = direct.find("2");
    if (it != direct.end()) {
        cout << it->second << endl;
    }
    
    Solution542().test();
    return 0;
}
