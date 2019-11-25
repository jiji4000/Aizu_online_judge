//
//  ALDS1_11_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/08/22.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include<iostream>
#include<queue>

using namespace std;

#define N 100
#define INFTY 99999999

int n,
// 隣接行列
M[N][N];
// 距離 colorも同時に管理する
int d[N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    
    // 距離を初期化
    for(int i = 0;i < n;++i){
        d[i] = INFTY;
    }
    d[s] = 0;
    // 対象の頂点番号
    int u;
    
    while(!q.empty()){
        u = q.front();
        q.pop();
        
        for(int v = 0;v < n;++v){
            // 頂点が隣接しているかつ未訪問
            if(M[u][v] == 1 && d[v] == INFTY){
                // 対象の頂点の距離は前の頂点 + 1
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    
}

int main(){
    int u,k,v;
    
    cin >> n;
    
    // 隣接行列を初期化
    for(int i = 0;i < n;++i){
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
    
    bfs(0);

    for(int i = 0;i < n;++i){
        cout << i + 1 << " " << ((d[i] == INFTY) ? (-1) : d[i]) << endl;
    }

    return 0;
}
