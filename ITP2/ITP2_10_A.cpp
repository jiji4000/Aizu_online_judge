//
//  ITP2_10_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/20.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <bitset>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    unsigned int n[4];
    cin >> n[0];
    
    // 反転
    n[1] = ~n[0];
    // 左シフト
    n[2] = n[0] << 1;
    // 右シフト
    n[3] = n[0] >> 1;
    
    for(int i = 0;i < 4;++i){
        cout << bitset<32>(n[i]) << endl;
    }
}

