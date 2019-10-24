//
//  ALDS1_5_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/24.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define N 100000

int main(void){
    int n;
    int nums[N];
    
    cin >> n;
    for(int j = 0;j < n;++j){
        cin >> nums[j];
    }
    // 末端
    int x = nums[n - 1];
    int i = 0;
    for(int j = 0;j < n - 1;++j){
        if(nums[j] <= x){
            swap(nums[i],nums[j]);
            ++i;
        }
    }
    swap(nums[i],nums[n - 1]);
    
    // 表示
    for(int j = 0;j < n;++j){
        if(j == i){
            cout << "[" << nums[j] << "]";
        }else{
            cout << nums[j];
        }
        
        if(j + 1 < n){
            cout << " ";
        }
    }
    cout << endl;
}
