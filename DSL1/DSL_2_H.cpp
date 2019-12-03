//
//  DSL_2_G.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/12/03.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include "stdio.h"
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int mySize = 1;
vector<ll> val;
vector<ll> lazy;

void lazyPropagate(int p) {
    val[p] += lazy[p];
    if (p < mySize - 1) {
        lazy[(p * 2) + 1] += lazy[p];
        lazy[(p * 2) + 2] += lazy[p];
    }
    lazy[p] = 0;
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
    val[k] = min(val[(k * 2) + 1],val[(k * 2) + 2]);
}

void add(int l1, int r1, int x) {
    add(l1, r1, 0, mySize, 0, x);
}

ll getMin(int l1, int r1, int l2, int r2, int k) {
    if (r1 <= l2 || r2 <= l1) {
        return __LONG_LONG_MAX__;
    }
    if (l1 <= l2 && r2 <= r1) {
        lazyPropagate(k);
        return val[k];
    }
    int mid = (l2 + r2) / 2;
    lazyPropagate(k);
    ll sl = getMin(l1, r1, l2, mid, (k * 2) + 1);
    ll sr = getMin(l1, r1, mid, r2, (k * 2) + 2);
    return min(sl,sr);
}

ll getMin(int l1, int r1) {
    return getMin(l1, r1, 0, mySize, 0);
}

int main(){
    int n,q,command,l,r,value;
    scanf("%d %d",&n,&q);
    for(;mySize < n;mySize <<= 1);
    val = vector<ll>(mySize * 2,0);
    lazy = vector<ll>(mySize * 2,0);
    
    for(int i = 0;i < q;++i){
        scanf("%d" "%d" "%d",&command,&l,&r);
        // add(s,t,x): as,as+1,...,at にxを加算する。
        if(command == 0){
            scanf("%d",&value);
            add(l,r + 1,value);
            // find(s,t) : report the minimum value in as,as+1,...,at.
        }else{
            printf("%lld\n",getMin(l,r + 1));
        }
    }
}
