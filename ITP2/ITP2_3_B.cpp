//
//  ITP2_3_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/10.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

static const int N = 1000;

int main(){
    int n,commandNum,a1[N],a2[N],b,c,d;
    cin >> n;
    for(int i = 0;i < n;++i){
        cin >> a1[i];
        a2[i] = a1[i];
    }
    cin >> commandNum;
    
    for(int i = 0;i < commandNum;++i){
        cin >> b >> c >> d;
        sort(a2 + c,a2 + d);
        switch(b){
                // min
            case 0:
                cout << a2[c] << endl;
                break;
                // max
            case 1:
                cout << a2[d - 1] << endl;
                break;
        }
        memcpy(a2, a1, sizeof(a1));
    }
}

