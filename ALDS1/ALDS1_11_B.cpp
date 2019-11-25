//
//  ALDS1_11_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/08/20.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include<iostream>

using namespace std;

#define N 100

int Graph[N][N];
// 頂点を発見した時刻
int d[N];
// 頂点の探索を終えた時刻
int f[N];
// かかった時間
int dTime = 0;
// 頂点を発見したかのフラグ
bool visited[N];

void visit(int i,int max){
    
    visited[i] = true;
    d[i] = ++dTime;
    for(int j = 0;j < max;++j){
        if(Graph[i][j] == 1 && !visited[j]){
            visit(j,max);
        }
    }
    // すべての頂点の探索が終了した
    f[i] = ++dTime;
}

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
            Graph[u][v] = 1;
        }
    }
    for(int i = 0;i < n;++i){
        if(!visited[i]){
            visit(i, n);
        }
    }
    
    for(int i = 0;i < n;++i){
        cout << i + 1 << " " << d[i] << " " << f[i] << endl;
    }
    
    return 0;
}
