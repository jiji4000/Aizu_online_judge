//
//  ITP2_11_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/22.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for(int i = 0;i < (1 << n);++i){
        cout << i << ":";
        for(int j = 0;j < n;++j){
            if(i & (1 << j)){
                cout << " " << j;
            }
        }
        cout << endl;
    }
}
