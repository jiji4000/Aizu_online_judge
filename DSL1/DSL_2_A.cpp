//
//  DSL_2_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/27.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include "iostream"
#include "math.h"
#include <algorithm>
using namespace std;

#define SUQARE_SIZE  100000

int block[SUQARE_SIZE];
int blockSize;

void updateTable(int arr[],int index,int val)
{
    // 更新
    arr[index] = val;
    // block内の最小値を更新する
    int blockNumber = index / blockSize;
    int startIndex = blockNumber * blockSize;
    int minValue = arr[startIndex];
    // blockを最小のものに更新し直す
    for (int i = startIndex + 1;i < startIndex + blockSize;++i) {
        minValue = min(minValue,arr[i]);
    }
    block[blockNumber] = minValue;
}

int query(int arr[],int l, int r)
{
    int minValue = __INT32_MAX__;
    // 左端
    while (l < r && l % blockSize != 0 && l != 0)
    {
        minValue = min(minValue,arr[l]);
        l++;
    }
    // blockに該当する部分
    while ((l + blockSize) <= r)
    {
        minValue = min(minValue,block[l / blockSize]);
        l += blockSize;
    }
    // 右端
    while (l <= r)
    {
        minValue = min(minValue,arr[l]);
        l++;
    }
    return minValue;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q,x,y,c;
    cin >> n >> q;
    int nums[n];
    for(int i = 0;i < n;++i){
        nums[i] = __INT_MAX__;
        block[i] = __INT_MAX__;
    }
    // block size
    blockSize = sqrt(n);
    
    for(int i = 0;i < q;++i){
        cin >> c >> x >> y;
        switch(c){
                // update
            case 0:
                updateTable(nums,x,y);
                break;
                // find
            case 1:
                cout << query(nums,x,y) << endl;
                break;
        }
    }
}
