//
//  DSL_2_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/28.
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
    arr[index] += val;
    // block内の合計値を更新する
    int blockNumber = index / blockSize;
    int startIndex = blockNumber * blockSize;
    int addValue = arr[startIndex];
    // ブロック内の最大値を更新する
    for (int i = startIndex + 1;i < startIndex + blockSize;++i) {
        addValue += arr[i];
    }
    block[blockNumber] = addValue;
}

int query(int arr[],int l, int r)
{
    int addValue = 0;
    // 左端
    while (l < r && l % blockSize != 0 && l != 0)
    {
        addValue += arr[l];
        l++;
    }
    // blockに該当する部分
    while ((l + blockSize) <= r)
    {
        addValue += block[l / blockSize];
        l += blockSize;
    }
    // 右端
    while (l <= r)
    {
        addValue += arr[l];
        l++;
    }
    return addValue;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q,x,y,c;
    cin >> n >> q;
    int nums[n];
    for(int i = 0;i < n;++i){
        nums[i] = 0;
        block[i] = 0;
    }
    // block size
    blockSize = sqrt(n);
    
    for(int i = 0;i < q;++i){
        cin >> c >> x >> y;
        x--;        // 1から!
        switch(c){
                // add(i,x): aiにxを加算する。
            case 0:
                updateTable(nums,x,y);
                break;
                // getSum(s,t): as,as+1,...,atの合計値を出力する。
            case 1:
                --y; // 1から!
                cout << query(nums,x,y) << endl;
                break;
        }
    }
}
