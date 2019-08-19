//
//  ALDS1_11_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/08/20.
//  Copyright © 2019 jiji4000. All rights reserved.
//


#include<iostream>

using namespace std;

#define N 100

int M[N][N];

int main(){
    int n,u,k,v;
  
    cin >> n;
    for(int i = 0;i < n;++i){
        cin >> u >> k;
        // 頂点を移動する
        u--;
        // 頂点の数だけ回す
        for(int j = 0;j < k;++j){
            cin >> v;
            --v;    // ずらす
            M[u][v] = 1;
        }
    }
    
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            // 2個目からは空白が必要
            if(j){
                cout << " ";
            }
            cout << M[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
