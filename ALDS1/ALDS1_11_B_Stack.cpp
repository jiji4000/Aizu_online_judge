//
//  ALDS1_11_B_Stack.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/08/21.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include<iostream>
#include<stack>
using namespace std;

#define N 100
// 未訪問
#define WHITE 0
// 訪問中
#define GRAY 1
// 訪問済み
#define BLACK 2

int n,M[N][N];
int color[N];
// 訪問時間
int d[N];
// 探索終了時間
int f[N];
// 時間
int t = 0;
// 探索済みの頂点を一から探索しないように、nt[u]にすでに探索済みの番号を入れ、次回は探索した移行の頂点から探索されるようにする
int nt[N];

/**
    uに隣接するvを番号順に取得する
*/
int next(int u){
    // 探索済み移行の頂点から探索を始める
    for(int v = nt[u];v < n;++v){
        nt[u] = v + 1;
        if(M[u][v]){
            return v;
        }
    }
    return -1;
}

/**
    スタックを用いた深さ優先探索
*/
void dfs(int u){
    for(int i = 0;i < n;++i){
        nt[i] = 0;
    }
    
    stack<int> S;
    S.push(u);
    color[u] = GRAY;    // 訪問中
    d[u] = ++t;      // 訪問時間
    
    while(!S.empty()){
        int topU = S.top();
        // 隣接する頂点
        int v = next(topU);
        // 隣接する頂点が見つかった場合
        if(v != -1){
            // 未探索のケース
            if(color[v] == WHITE){
                color[v] = GRAY;
                // 訪問時間
                d[v] = ++t;
                S.push(v);
            }
        }else{
            // 未訪問の頂点が見つからなかった
            S.pop();
            // 探索終了
            color[topU] = BLACK;
            // 探索終了時間
            f[topU] = ++t;
        }
    }
}

int main(){
    int u,k,v;
    cin >> n;
    
    // 初期化
    for(int i = 0;i < n;++i){
        color[i] = WHITE;
        for(int j = 0;j < n;++j){
            M[i][j] = 0;
        }
    }
    
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
        if(color[i] == WHITE){
            dfs(i);
        }
    }
    
    for(int i = 0;i < n;++i){
        cout << i + 1 << " " << d[i] << " " << f[i] << endl;
    }
    
    return 0;
}

