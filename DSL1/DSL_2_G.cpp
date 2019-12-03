//
//  DSL_2_G.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/12/03.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include "stdio.h"
#include "math.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int mySize = 1;
vector<ll> val;
vector<ll> lazy;
vector<int> width;

void lazyPropagate(int p) {
    if (lazy[p] > 0) {
        val[p] += lazy[p] * width[p];
        if (p < mySize - 1) {
            lazy[(p * 2) + 1] += lazy[p];
            lazy[(p * 2) + 2] += lazy[p];
        }
        lazy[p] = 0;
    }
}

void add(int l1, int r1, int l2, int r2, int k, int x) {
    if (r1 <= l2 || r2 <= l1) {
        lazyPropagate(k);
        return;
    }
    if (l1 <= l2 && r2 <= r1) {
        lazy[k] += x;
        lazyPropagate(k);
        return;
    }
    int mid = (l2 + r2) / 2;
    lazyPropagate(k);
    add(l1, r1, l2, mid, (k * 2) + 1, x);
    add(l1, r1, mid, r2, (k * 2) + 2, x);
    val[k] = val[(k * 2) + 1] + val[(k * 2) + 2];
}

void add(int l1, int r1, int x) {
    add(l1, r1, 0, mySize, 0, x);
}

ll getSum(int l1, int r1, int l2, int r2, int k) {
    if (r1 <= l2 || r2 <= l1) {
        return 0;
    }
    if (l1 <= l2 && r2 <= r1) {
        lazyPropagate(k);
        return val[k];
    }
    int mid = (l2 + r2) / 2;
    lazyPropagate(k);
    ll sl = getSum(l1, r1, l2, mid, (k * 2) + 1);
    ll sr = getSum(l1, r1, mid, r2, (k * 2) + 2);
    return sl + sr;
}

ll getSum(int l1, int r1) {
    return getSum(l1, r1, 0, mySize, 0);
}

int main(){
    int n,q,command,l,r,value;
    scanf("%d %d",&n,&q);
    for(;mySize < n;mySize <<= 1);
    val = vector<ll>(mySize * 2,0);
    lazy = vector<ll>(mySize * 2,0);
    width = vector<int>(mySize * 2,1);
    
    for (int i = mySize - 2; i >= 0; --i) {
        width[i] = width[(i * 2) + 1] + width[(i * 2) + 2];
    }

    for(int i = 0;i < q;++i){
        scanf("%d" "%d" "%d",&command,&l,&r);
        --l;
        --r;
        // add(s,t,x): as,as+1,...,at にxを加算する。
        if(command == 0){
            scanf("%d",&value);
            add(l,r + 1,value);
        // getSum(s,t): as,as+1,...,atの合計値を出力する。
        }else{
            printf("%lld\n",getSum(l,r + 1));
        }
    }
}
