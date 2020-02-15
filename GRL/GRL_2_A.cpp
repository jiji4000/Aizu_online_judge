//
//  GRL_2_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2020/02/16.
//  Copyright © 2020 jiji4000. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class DisjointSet{
public:
    vector<int> p,rank;
    
    DisjointSet();
    DisjointSet(int size){
        rank.resize(size,0);
        p.resize(size,0);
        for(int i = 0;i < size;++i){
            makeSet(i);
        }
    }
    
    void makeSet(int x){
        p[x] = x;
        rank[x] = 0;
    }
    
    bool same(int x,int y){
        return findSet(x) == findSet(y);
    }
    
    void unite(int x,int y){
        link(findSet(x),findSet(y));
    }
    
    void link(int x,int y){
        if(rank[x] > rank[y]){
            p[y] = x;
        }else{
            p[x] = y;
            if(rank[x] == rank[y]){
                rank[y]++;
            }
        }
    }
    
    int findSet(int x){
        if(x != p[x]){
            p[x] = findSet(p[x]);
        }
        return p[x];
    }
};

class Edge{
public:
    int source,target,cost;
    Edge(int source = 0,int target = 0,int cost = 0):
    source(source),target(target),cost(cost){}
    
    bool operator < (const Edge &e) const {
        return cost < e.cost;
    }
};

int kruskal(int n,vector<Edge> edges){
    int totalCost = 0;
    sort(edges.begin(),edges.end());
    
    DisjointSet dSet = DisjointSet(n + 1);
    
    for(int i = 0;i < n;++i){
        dSet.makeSet(i);
    }
    
    int source,target;
    
    for(int i = 0;i < edges.size();++i){
        Edge e = edges[i];
        if(!dSet.same(e.source,e.target)){
            totalCost += e.cost;
            dSet.unite(e.source,e.target);
            
        }
    }
    return totalCost;
}

int main(){
    int n,m,cost,source,target;
    vector<Edge> edges;
    cin >> n >> m;
    
    for(int i = 0;i < m;++i){
        cin >> source >> target >> cost;
        edges.push_back(Edge(source,target,cost));
    }
    cout << kruskal(n,edges) << endl;
}
