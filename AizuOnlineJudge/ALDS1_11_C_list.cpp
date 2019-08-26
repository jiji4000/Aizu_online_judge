//
//  ALDS_1_11_C_list.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/08/26.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

#define N 100
#define INFTY 99999999
vector<int>list[N];
int color[N];

int n;

// 距離 colorも同時に管理する
int d[N];

// 幅優先探索
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
        // 頂点分探索する
        for(int i = 0;i < list[u].size();++i){
            // 隣接する頂点
            int v = list[u][i];
            // 頂点が未訪問
            if(d[v] == INFTY){
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
    
    for(int i = 0;i < n;++i){
        cin >> u >> k;
        // 頂点を移動する
        u--;
        // 頂点の数だけ回す
        for(int j = 0;j < k;++j){
            cin >> v;
            // 隣接行列に挿入する
            list[u].push_back(v - 1);
        }
    }
    
    bfs(0);
    
    for(int i = 0;i < n;++i){
        cout << i + 1 << " " << ((d[i] == INFTY) ? (-1) : d[i]) << endl;
    }
    
    return 0;
}
