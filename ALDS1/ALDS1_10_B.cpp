//
//  ALDS1_10_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/28.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define N 100

int main(void){
    int n;
    int p[N + 1],m[N + 1][N + 1] = {};
    
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> p[i - 1] >> p[i];
    }
    for(int l = 2;l <= n;++l){
        for(int i = 1;i <= n - l + 1;++i){
            int j = i + l - 1;
            m[i][j] = __INT_MAX__;
            for(int k = i;k <= j - 1;++k){
                m[i][j] = min(m[i][j],m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
        }
    }
    cout << m[1][n] << endl;
}
