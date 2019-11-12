//
//  ITP2_4_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/12.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n1,commandNum,b,e,t;
    cin >> n1;
    vector<int>a1(n1),a2(n1);
    for(int i = 0;i < n1;++i){
        cin >> a1[i];
        a2[i] = a1[i];
    }
    cin >> commandNum;
    for(int i = 0;i < commandNum;++i){
        cin >> b >> e >> t;
        // 左側文字列を右側に代入する
        for(int k = b;k < b + (e - b);++k){
            int moveIndex = (k - b) + t;
            a2[moveIndex] = a1[k];
        }
        // 右側文字列を左側に代入する
         for(int k = t;k < t + (e - b);++k){
             int moveIndex = b + (k - t);
             a2[moveIndex] = a1[k];
         }
        copy(a2.begin(),a2.end(),a1.begin());
    }
    for(int i = 0;i < n1;++i){
        if(i) cout << " ";
        cout << a2[i];
    }
    cout << endl;
}
