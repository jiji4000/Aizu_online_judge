//
//  ITP2_10_B.cpp
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
    unsigned int n[5];
    cin >> n[0] >> n[1];
    
    // AND
    n[2] = n[0] & n[1];
    // OR
    n[3] = n[0] | n[1];
    // XOR
    n[4] = n[0] ^ n[1];
    
    for(int i = 2;i < 5;++i){
        cout << bitset<32>(n[i]) << endl;
    }
}
