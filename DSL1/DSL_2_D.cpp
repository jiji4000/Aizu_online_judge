//
//  DSL_2_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/30.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include "stdio.h"
#include "math.h"
#include <algorithm>
using namespace std;

#define SUQARE_SIZE  100000

int block[SUQARE_SIZE];
int blockSize;
int n;

void updateArr(int arr[],int left,int num){
    for(int i = left;i < left + blockSize;++i){
        if(i >= n){
            break;
        }
        arr[i] = num;
    }
}

void update(int arr[],int l, int r,int value)
{
    // 左端
    if(l % blockSize != 0 && l != 0 && l < r){
        int blockNumber = l / blockSize;
        if(block[blockNumber] != __INT_MAX__){
            updateArr(arr,blockNumber * blockSize,block[blockNumber]);
            block[blockNumber] = __INT_MAX__;
        }
        do{
            arr[l] = value;
            l++;
        }while(l % blockSize != 0 && l < r);
    }
    // blockに該当する部分
    while ((l + blockSize) <= r)
    {
        block[l / blockSize] = value;
        l += blockSize;
    }
    if(l <= r){
        int blockNumber = r / blockSize;
        if(block[blockNumber] != __INT_MAX__){
            updateArr(arr,blockNumber * blockSize,block[blockNumber]);
            block[blockNumber] = __INT_MAX__;
        }
        // 右端
        do{
            arr[l] = value;
            l++;
        }while(l <= r);
    }
}

int query(int arr[],int index)
{
    int blockNumber = index / blockSize;
    if(block[blockNumber] != __INT_MAX__){
        return block[blockNumber];
    }
    else{
        return arr[index];
    }
}

int main(){
    int q,command;
    scanf("%d %d",&n,&q);
    int a[n];
    blockSize = sqrt(n);
    
    for(int i = 0;i < n;++i){
        a[i] = block[i] = __INT_MAX__;
    }
    
    for(int i = 0;i < q;++i){
        scanf("%d",&command);
        if(command == 0){
            int l,r,value;
            scanf("%d %d %d",&l,&r,&value);
            update(a,l,r,value);
        }else{
            int index;
            scanf("%d",&index);
            printf("%d\n",query(a, index));
        }
    }
}
