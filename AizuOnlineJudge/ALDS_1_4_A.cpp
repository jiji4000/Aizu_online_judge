//
//  ALDS_1_4_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2018/12/02.
//  Copyright © 2018年 jiji4000. All rights reserved.
//

#include <stdio.h>

bool linearSearch(int row[],int n,int key){
    int i = 0;
    // 末端に番兵を仕込む
    row[n] = key;
    for(i = 0;i <= n;++i){
        if(row[i] == key) break;
    }
    return i != n;
}

int main(){
    int n,row[10000 + 1],q,key,sum = 0;
    // 一つ目
    scanf("%d",&n);
    for(int i = 0;i < n;++i){
        scanf("%d",&row[i]);
    }

    // 探索する数
    scanf("%d",&q);
    for(int i = 0;i < q;++i){
        scanf("%d",&key);
        if(linearSearch(row, n, key)){
            ++sum;
        }
    }
    printf("%d\n",sum);
    return 0;
}
