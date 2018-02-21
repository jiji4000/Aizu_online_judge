//
//  ALDS1_12_B_SingleSortestPath.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2018/02/21.
//  Copyright © 2018年 jiji4000. All rights reserved.
//

#include <iostream>
using namespace std;
#define MAX 100
#define INFTY 1<<22
#define WHITE 0
#define GRAY 1
#define BLACK 2

int gMatrix[MAX][MAX];

void dijkstra(int n){
    // 最小の重みを記録する
    int minV;
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
    
    while(1){
        minV = INFTY;
        // 頂点を示す
        int u = -1;
        // 2.1weight[u]が最小である頂点を決定する
        for(int i = 0;i < n;++i){
            if(minV > weight[i] && color[i] != BLACK){
                u = i;
                minV = weight[i];
            }
        }
        if(u == -1)break;
        color[u] = BLACK;
        
        for(int v = 0;v < n;++v){
            // 辺が存在する
            if(color[v] != BLACK && gMatrix[u][v] != INFTY){
                // 2.2最短コストを更新する
                // この処理の終了後weight[v]sからS内の頂点のみを経由したvまでの最短コストが記録される
                if(weight[v] > weight[u] + gMatrix[u][v]){
                    weight[v] = weight[u] + gMatrix[u][v];
                    color[v] = GRAY;
                }
            }
        }
    }
    // 出力
    for(int i = 0;i < n;++i){
        cout << i << " " << ( weight[i] == INFTY ? -1 : weight[i] ) << endl;
    }
}

int main(){
    int n;
    cin >> n;
    
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            gMatrix[i][j] = INFTY;
        }
    }
    
    int k,c,u,v;
    for(int i = 0;i < n;++i){
        cin >> u >> k;
        for(int j = 0;j < k;++j){
            cin >> v >> c;
            gMatrix[u][v] = c;
        }
    }
    dijkstra(n);
    return 0;
}
