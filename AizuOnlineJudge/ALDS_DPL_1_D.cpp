//
//  ALDS_DPL_1_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/07/25.
//  Copyright © 2019年 jiji4000. All rights reserved.
//

#include<iostream>
#include<algorithm>

using namespace std;

#define MAX 100000

int n,A[MAX + 1],L[MAX];

/**
 最長増加部分列の長さを返す
*/
int lis(){
    // 0には初期値を
    L[0] = A[0];
    int length = 1;
    
    // 1から詮索する
    for(int i = 1;i < n;++i){
        // LISの最後の要素に追加
        if(L[length - 1] < A[i]){
            L[length++] = A[i];
        }else{
            // 2分探索を使い、選択した値をLが昇順になるように代入する
            *lower_bound(L,L + length,A[i]) = A[i];
        }
    }
    return length;
}

int main(){
    cin >> n;
    for(int i = 0;i < n;++i){
        cin >> A[i];
    }
    
    cout << lis() << endl;
    return 0;
}
