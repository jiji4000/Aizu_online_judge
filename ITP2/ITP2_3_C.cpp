//
//  ITP2_3_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/11.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
using namespace std;

static const int N = 1000;

int main(){
    int n,commandNum,a[N],b,e,k,cnt;
    cin >> n;
    for(int i = 0;i < n;++i){
        cin >> a[i];
    }
    cin >> commandNum;
    
    for(int i = 0;i < commandNum;++i){
        cin >> b >> e >> k;
        cnt = 0;
        for(int i = b;i < e;++i){
            if(a[i] == k){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}
