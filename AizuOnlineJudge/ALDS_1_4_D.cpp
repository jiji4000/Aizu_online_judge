//
//  ALDS_1_4_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2018/12/09.
//  Copyright © 2018年 jiji4000. All rights reserved.
//
#include <stdio.h>
#include <iostream>

#define MAX 100000

int n,k;
long T[MAX];

int check(long p){
    int i = 0;
    for(int j = 0;j < k;++j){
        long s = 0;
        while(s + T[i] <= p){
            s += T[i];
            ++i;
            if(i == n){
                return n;
            }
        }
    }
    return i;
}

long solve(){
    long left = 0;
    // 荷物の個数 * 一個あたりの最大重量
    long right = 100000 * 10000;
    long mid;
    while(right - left > 1){
        mid = (left + right) / 2;
        // Pを暫定的に決める
        int v = check(mid);
        if(v >= n){
            right = mid;
        }
        else{
            left = mid;
        }
    }
    return right;
}

int main(){
    std::cin >> n >> k;
    for(int i = 0;i < n;++i){
        std::cin >> T[i];
    }
    long ans = solve();
    printf("%ld\n",ans);
    return 0;
}
