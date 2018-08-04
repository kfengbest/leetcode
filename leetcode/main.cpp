//
//  main.cpp
//  leetcode
//
//  Created by fengka on 7/30/18.
//  Copyright © 2018 fengka. All rights reserved.
//

#include <iostream>
#include "350.h"
#include <string>
#include <unordered_map>
#include "sort.h";
#include "tree.h"
#include "tree2.h"

string reverseString(string s) {
    int mid = s.size() / 2;
    char temp;
    for(int left = 0; left < mid; left++){
        int right = s.size() - 1 - left;
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
    }
    
    return s;
}


//int firstUniqChar(string s) {
//    unordered_map<int, int> cache;
//    for(int i = 0; i < s.size(); i++){
//        if (cache.find(s[i]) != cache.end()) {
//            cache[s[i]]++;
//        }else{
//            cache[s[i]]  = 1;
//        }
//    }
//
//    for(auto i : cache){
//        if(i.second == 1)
//            return
//    }
//}

int firstUniqChar(string s) {
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < s.size(); j++)
        {
            if(j == i)
                continue;
            
            if(s[i] == s[j])
                break;
            
            if(j+1 == s.size() && s[i] != s[j])
                return i;
                
        }
    }
    return -1;
}


int main(int argc, const char * argv[]) {
    // insert code here...

    //sort::test();
    
    //tree::test();
    
    Tree2::Tester tester;
    tester.test();
    
    std::cout << "Hello, World!\n";
    return 0;
}
