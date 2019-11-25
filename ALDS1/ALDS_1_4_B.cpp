//
//  ALDS_1_4_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2018/12/06.
//  Copyright © 2018年 jiji4000. All rights reserved.
//

#include <stdio.h>

bool binarySearch(int row[],int n,int key){
    int left = 0;
    int right = n;
    
    while(left < right){
        int center = (left + right) / 2;
        if(row[center] == key){
            return true;
        }
        else if(row[center] < key){
            left  = center + 1;
        }
        else{
             right = center;
        }
    }
    return false;
}

int main(){
    int n,row[100000 + 1],q,key,sum = 0;
    // 一つ目
    scanf("%d",&n);
    for(int i = 0;i < n;++i){
        scanf("%d",&row[i]);
    }

    // 探索する数
    scanf("%d",&q);
    for(int i = 0;i < q;++i){
        scanf("%d",&key);
        if(binarySearch(row, n, key)){
            ++sum;
        }
    }
    printf("%d\n",sum);
    return 0;
}
