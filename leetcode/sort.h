//
//  sort.h
//  leetcode
//
//  Created by fengka on 8/2/18.
//  Copyright © 2018 fengka. All rights reserved.
//

#ifndef sort_h
#define sort_h
#include <iostream>
#include <vector>


using namespace std;

namespace sort {
    
    void print(vector<int>& arr){
        std::cout << "[";
        for(auto i : arr){
            std::cout << i << " ";
        }
        std::cout << "]" << std::endl;
    }
    
    void swap(vector<int>& arr, int i, int j){
        int temp = 0;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    /*
     1. 比较相邻的元素，如果第一个比第二个大，交换它们。
     2. 对每一对相邻的元素做同样的工作，从开始一对到最后一对。
     3. 对所有的元素都重复以上操作，除了最后一个。
     4. 重复1-3，直到排序结束。
     */
    void bubble_sort(vector<int>& arr){
        unsigned int len = (unsigned int)arr.size();
        for(int r = len-1; r >= 0; r--){
            for(int l = 0; l < r; l++){
                if(arr[l] > arr[l+1])
                    swap(arr,l,l+1);
            }
        }
    }
    
    int min(vector<int>& arr, int l, int r){
        int candidate = arr[l];
        int index = l;
        for(int i = l+1; i <= r; i++){
            if(arr[i] < candidate){
                candidate = arr[i];
                index = i;
            }
        }
        return index;
    }
    /*
    1. 游标h指向数组头部。
    2. 从游标位置到数组尾部位置中找到一个最小的元素 a[i]
    3. 将最小元素与游标位置交换。
    4. 游标右移，直到数组尾部。
    */
    void select_sort(vector<int>& arr){
        unsigned int len = (unsigned int)arr.size();
        for(int left = 0; left < len; left++){
            int minIndex = min(arr, left, len-1);
            swap(arr, left, minIndex);
        }
    }
    
    void _insertFromLast(vector<int>& arr, int left, int right, int current){
        int i = right;
        while(i>left){
            if(arr[current] > arr[i]) // find the index
                i--;
            else
            {
                //_doInsert(arr, i, current); // insert(swap) into index.
                int temp = arr[current];
                int idxTemp = current;
                while(idxTemp > i){
                    arr[idxTemp] = arr[idxTemp-1];
                }
                arr[i] = temp;
            }
        }
    }
    
    /*
     . 定义一个游标h，作为新数组的尾部游标。
     . 从未排序区间中取一个数，插入到已排序区间中。
     . 插入的方法： 从后往前找，如果比当前数小，就插到前面。
    */
    void insert_sort(vector<int>& arr){
        unsigned int len = arr.size();
        for(int left = 0; left < len; left++ ){
            _insertFromLast(arr, 0, left, left+1);
        }
    }
    
    void test(){
        vector<int> d1 = {3,3,1,2,5,7};
        //bubble_sort(d1);
        //select_sort(d1);
        insert_sort(d1);
        print(d1);
    }
}



#endif /* sort_h */
