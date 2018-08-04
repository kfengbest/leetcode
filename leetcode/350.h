//
//  350.h
//  leetcode
//
//  Created by fengka on 7/30/18.
//  Copyright © 2018 fengka. All rights reserved.
//

#ifndef _50_h
#define _50_h

#include <vector>
#include <iostream>

using namespace std;

class Solution_350 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 || nums2.size() == 0) {
            return vector<int>();
        }
        
        int i = 0, j = 0;
        vector<int> big, small;
        if (nums1.size() > nums2.size()) {
            big = nums1;
            small = nums2;
        }else{
            big = nums2;
            small = nums1;
        }
        
        while(i < big.size()){
            if(big[i] != small[j]){
                // i move forard.
                // j do nothing.
                i++;
            }
            else{
                j++;
                while(j < small.size()){
                    if(big[i+j] == small[j])
                    {
                        j++;
                    }
                    else{
                        j = 0;
                        break;
                    }
                }
                i++;
                if(j == small.size())
                    return small;
            }
        }
        return  vector<int>();
    }
    
    void test(){
        vector<int> a = {1,2,2,1};
        vector<int> b = {2,2};
        
        auto ab = intersect(a, b);
        for(auto i : ab)
            std::cout << i << " ";
        
        vector<int> c = {1,2};
        vector<int> d = {1,1};
        auto cd = intersect(c, d);
        for(auto i : cd)
            std::cout << i << " ";
        
        vector<int> e = {};
        vector<int> f = {};
        auto ef = intersect(e, f);
        for(auto i : ef)
            std::cout << i << " ";
    }
};

#endif /* _50_h */
