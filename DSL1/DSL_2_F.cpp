//
//  DSL_2_F.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/12/01.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include "stdio.h"
#include "math.h"
#include <algorithm>
#include <vector>
using namespace std;

int size = 1;
vector<int> val;
vector<int> lazy;

void lazyPropagate(int p) {
    if (lazy[p] != -1) {
        val[p] = lazy[p];
        if (p < size - 1) {
            lazy[(p * 2) + 1] = lazy[p];
            lazy[(p * 2) + 2] = lazy[p];
        }
        lazy[p] = -1;
    }
}

void update(int l1, int r1, int l2, int r2, int k, int x) {
    if (r1 <= l2 || r2 <= l1) {
        lazyPropagate(k);
        return;
    }
    if (l1 <= l2 && r2 <= r1) {
        lazy[k] = x;
        lazyPropagate(k);
        return;
    }
    int mid = (l2 + r2) / 2;
    lazyPropagate(k);
    update(l1, r1, l2, mid,(k * 2) + 1, x);
    update(l1, r1, mid, r2,(k * 2) + 2, x);
    val[k] = min(val[(k * 2) + 1], val[(k * 2) + 2]);
}

void update(int l, int r, int x) {
    update(l, r, 0, size, 0, x);
}

int getmin(int l1, int r1, int l2, int r2, int k) {
    if (r1 <= l2 || r2 <= l1) {
        return __INT_MAX__;
    }
    if (l1 <= l2 && r2 <= r1) {
        lazyPropagate(k);
        return val[k];
    }
    int mid = (l2 + r2) / 2;
    lazyPropagate(k);
    int ml = getmin(l1, r1, l2, mid,(k * 2) + 1);
    int mr = getmin(l1, r1, mid, r2,(k * 2) + 2);
    return min(ml, mr);
}

int getmin(int l, int r) {
    return getmin(l, r, 0, size, 0);
}

int main(){
    int n,q,command,l,r,value;
    scanf("%d %d",&n,&q);
    for(;size < n;size <<= 1);
    val = vector<int>(size * 2,__INT_MAX__);
    lazy = vector<int>(size * 2, -1);
    
    for(int i = 0;i < q;++i){
        scanf("%d" "%d" "%d",&command,&l,&r);
        // update(s,t,x): as,as+1,...,at をxに変更する。
        if(command == 0){
            scanf("%d",&value);
            update(l,r + 1,value);
        // find(s,t): as,as+1,...,atの最小値を出力する。
        }else{
            printf("%d\n",getmin(l,r + 1));
        }
    }
}
