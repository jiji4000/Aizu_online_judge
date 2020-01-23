#include <iostream>
#include <queue>
using namespace std;
#define MAX 100000
#define WHITE 0
#define GRAY 1
#define BLACK 2

// 重み付き有向グラフの隣接リスト
vector<pair<int,int> > adj[MAX];

void dijkstra(int n,int startIndex){
    priority_queue<pair<int,int> >pq;
    // weight[v]に始点sからvまでの最短コストを保存する
    int weight[MAX];
    // 訪問状態を記録
    int color[MAX];
    // 1.初期化
    for(int i = 0;i < n;++i){
        weight[i] = __INT_MAX__;
        color[i] = WHITE;
    }
    
    // 始点
    weight[startIndex] = 0;
    color[startIndex] = GRAY;
    pq.push(make_pair(0,startIndex));
    
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
    
    for(int i = 0;i < n;++i){
        if(weight[i] == __INT_MAX__){
            cout << "INF" << endl;
        }
        else{
            cout << weight[i] << endl;
        }
    }
}

int main(){
    int begin,vNum,sideNum;
    cin >> vNum >> sideNum >> begin;
    
    int s,t,d;
    for(int i = 0;i < sideNum;++i){
        cin >> s >> t >> d;
        //gMatrix[s][t] = d;
        adj[s].push_back(make_pair(t,d));
    }
    dijkstra(vNum,begin);
}
