//
//  ALDS1_10_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/27.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define N 501

int main(){
    int n;
    double p[N],q[N];
    double pSum[N][N],qSum[N][N];
    double d[N][N];
    double t;
    
    cin >> n;
    
    for(int i = 0;i < n;++i){
        cin >> p[i];
    }
    
    for(int i = 0;i < n + 1;++i){
        cin >> q[i];
        d[i][i] = q[i];
    }
    
     // p
    for(int i = 0;i < n;++i){
        pSum[i][i] = p[i];
        for(int j = i + 1;j < n;++j){
            pSum[i][j] = pSum[i][j - 1] + p[j];
        }
    }
    
    // q
    for(int i = 0;i < n + 1;++i){
        qSum[i][i] = q[i];
        for(int j = i + 1;j < n + 1;++j){
            qSum[i][j] = qSum[i][j - 1] + q[j];
        }
    }
    
    for(int i = 1;i < n + 1;++i){
        for(int j = 0;j < (n + 1) - i;++j){
            d[j][j + i] = __DBL_MAX__;
            for(int k = 0;k < i;++k){
                t = d[j][j + k] + d[j + k + 1][j + i] + pSum[j][j + i - 1] + qSum[j][j + i];
                d[j][j + i] = min(d[j][j + i], t);
            }
        }
    }
    
    printf("%.8lf\n",d[0][n]);
    
    return 0;
}
