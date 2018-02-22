//
//  ALDS1_12_B_SingleSortestPath.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2018/02/21.
//  Copyright © 2018年 jiji4000. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 10000
#define INFTY 1<<22
#define WHITE 0
#define GRAY 1
#define BLACK 2

// 重み付き有向グラフの隣接リスト
vector<pair<int,int> > adj[MAX];

void dijkstra(int n){
    priority_queue<pair<int,int> >pq;
    // weight[v]に始点sからvまでの最短コストを保存する
    int weight[MAX];
    // 訪問状態を記録
    int color[MAX];
    // 1.初期化
    for(int i = 0;i < n;++i){
        weight[i] = INFTY;
        color[i] = WHITE;
    }
    
    // 始点
    weight[0] = 0;
    color[0] = GRAY;
    pq.push(make_pair(0,0));
    
    // 2
    while(!pq.empty()){
        // 2.1最小である頂点の決定
        pair<int,int> first = pq.top();
        pq.pop();
        // 頂点
        int u = first.second;
        color[u] = BLACK;
        
        // 最短値を取りだして、最短でなければ飛ばす
        if(weight[u] < first.first * -1) continue;
        // uに隣接する頂点vが存在する限り最短店を更新する
        for(int i = 0;i < adj[u].size();++i){
            int v = adj[u][i].first;
            if(color[v] == BLACK)continue;
            // 2.2最短点の更新
            if(weight[v] > weight[u] + adj[u][i].second){
                weight[v] = weight[u] + adj[u][i].second;
                // priority_queueはデフォルトで大きい値を優先するので-にする
                pq.push(make_pair(weight[v] * -1, v));
                color[v] = GRAY;
            }
        }
    }
    
    // 出力
    for(int i = 0;i < n;++i){
        cout << i << " " << ( weight[i] == INFTY ? -1 : weight[i] ) << endl;
    }
}

int main(){
    int n,k,c,u,v;
    cin >> n;
    
    for(int i = 0;i < n;++i){
        cin >> u >> k;
        for(int j = 0;j < k;++j){
            cin >> v >> c;
            adj[u].push_back(make_pair(v,c));
        }
    }
    dijkstra(n);
    return 0;
}
