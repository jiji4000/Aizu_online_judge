
//
//  ALDS_1_11_D_Connected_Components.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2018/02/16.
//  Copyright © 2018年 jiji4000. All rights reserved.
//

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

#define MAX 1000000
#define NIL -1

vector<int>gGraph[MAX];
int color[MAX];

void dfs(int r,int c){
    stack<int>s;
    s.push(r);
    color[r] = c;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        for(int i = 0;i < gGraph[u].size();++i){
            int v = gGraph[u][i];
            if(color[v] == NIL){
                color[v] = c;
                s.push(v);
            }
        }
    }
}

void assignColor(int number){
    int id = 1;
    for(int i = 0;i < number;++i){
        color[i] = NIL;
    }
    for(int i = 0;i < number;++i){
        if(color[i] == NIL)dfs(i,id++);
    }
}

int main(){
    int s,t,m,q,n;
    
    cin >> n >> m;
    
    for(int i = 0;i < m;++i){
        cin >> s >> t;
        gGraph[s].push_back(t);
        gGraph[t].push_back(s);
    }
    
    assignColor(n);
    
    cin >> q;
    
    for(int i = 0;i < q;++i){
        cin >> s >> t;
        if(color[s] == color[t]){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}
