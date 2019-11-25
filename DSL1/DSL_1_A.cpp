//
//  DSL_1_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/25.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <stdio.h>
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

int main(void){
    int n,q,x,y,c;
    cin >> n >> q;
    DisjointSet ds = DisjointSet(n);
    
    for(int i = 0;i < q;++i){
        cin >> c >> x >> y;
        switch(c){
            case 0:
                ds.unite(x, y);
                break;
            case 1:
                cout << ds.same(x, y) << endl;
                break;
        }
    }
}
