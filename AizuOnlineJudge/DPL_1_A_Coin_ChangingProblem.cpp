//
//  DPL_1_A_Coin_ChangingProblem.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2018/02/27.
//  Copyright © 2018年 jiji4000. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define M_MAX 20
#define N_MAX 50000
#define INFTY 1 << 29

int main(){
    int n,m;
    int coin[21];
    int T[N_MAX + 1];
    
    cin >> n >> m;
    // コインに額面を代入する
    for(int i = 1;i <= m;++i){
        cin >> coin[i];
    }
    
    // 最大値で初期化
    for(int i = 0;i < N_MAX;++i){
        T[i] = INFTY;
    }
    T[0] = 0;
    for(int i = 1;i <= m;++i){
        for(int j = 0;j + coin[i] <= n;++j){
            T[j + coin[i]] = min(T[j + coin[i]],T[j] + 1);
        }
    }
    cout << T[n] << endl;
    return 0;
}
