//
//  DSL_4_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/12/12.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long ll;
// 領域は2000まで
static const int MAX = 2000;

size_t compress(vector<int> &xs,map<int,int> &x){
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    for(int i = 0;i < xs.size();++i){
        x[xs[i]] = i;
    }
    return xs.size();
}

int main(){
    int n;
    scanf("%d",&n);
    int x1[MAX],x2[MAX],y1[MAX],y2[MAX];
    static int field[MAX * 2][MAX * 2] = {};
    vector<int> xs,ys;
    map<int,int> x,y;

    for(int i = 0;i < n;++i){
        scanf("%d %d %d %d",x1 + i,y1 + i,x2 + i,y2 + i);
        xs.push_back(x1[i]);
        xs.push_back(x2[i]);
        ys.push_back(y1[i]);
        ys.push_back(y2[i]);
    }
    
    size_t w = compress(xs,x);
    size_t h = compress(ys,y);

    for(int i = 0;i < n;++i){
        int xx1 = x[x1[i]], xx2 = x[x2[i]], yy1 = y[y1[i]], yy2 = y[y2[i]];
        field[xx1][yy1]++;
        field[xx2][yy2]++;
        field[xx1][yy2]--;
        field[xx2][yy1]--;
    }
    for(int i = 1;i < w;++i){
        for(int j = 0;j < h;++j){
            field[i][j] += field[i - 1][j];
        }
    }
    for(int i = 1;i < h;++i){
        for(int j = 0;j < w;++j){
            field[j][i] += field[j][i - 1];
        }
    }
    
    ll ans = 0;
    for(int i = 0;i < w;++i){
        for(int j = 0;j < h;++j){
            ll dx = xs[i + 1] -xs[i], dy = ys[j + 1] - ys[j];
            if(field[i][j] > 0){
                ans += dx * dy;
            }
        }
    }
    printf("%lld\n",ans);
}
