//
//  DLS_2_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/29.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include "stdio.h"

using namespace std;

static const int NIL = -1;
static const int MAX = 1000000;

class Node{
public:
    int location;
    int p,l,r;
    Node(){
        location = p = l = r = NIL;
    }
};

class Point{
public:
    int id,x,y;
    Point(){
        id = x = y = 0;
    }
    Point(int id,int x,int y):id(id),x(x),y(y){
        
    }
    
    bool operator < (const Point &p) const {
        return id < p.id;
    }
    
    void outPutId(){
        //cout << id << endl;
        printf("%d\n",id);
    }
};

int N;
Point point[MAX];
Node tree[MAX];
int np = 0;

bool lessX(const Point &p1,const Point &p2){
    return p1.x < p2.x;
}

bool lessY(const Point &p1,const Point &p2){
    return p1.y < p2.y;
}

int makeKDTree(int l,int r,int depth){
    if(l >= r) return NIL;
    int mid = (l + r) / 2;
    int t = np++;
    
    if(depth % 2 == 0){
        sort(point + l,point + r,lessX);
    }else{
        sort(point + l,point + r,lessY);
    }
    tree[t].location = mid;
    tree[t].l = makeKDTree(l,mid, depth + 1);
    tree[t].r = makeKDTree(mid + 1,r,depth + 1);
    
    return t;
}

void find(int v,int sx,int tx,int sy,int ty,int depth,vector<Point> &ans){
    int x = point[tree[v].location].x;
    int y = point[tree[v].location].y;
    
    // 範囲内なら領域を入れる
    if(sx <= x && x <= tx && sy <= y && y <= ty){
        ans.push_back(point[tree[v].location]);
    }
    
    // 偶数x
    if(depth % 2 == 0){
        if(tree[v].l != NIL){
            if(sx <= x){
                find(tree[v].l,sx,tx,sy,ty,depth + 1,ans);
            }
            
        }
        if(tree[v].r != NIL){
            if(x <= tx){
                find(tree[v].r,sx,tx,sy,ty,depth + 1,ans);
            }
        }
    // 奇数がy
    }else{
        if(tree[v].l != NIL){
            if(sy <= y){
                find(tree[v].l,sx,tx,sy,ty,depth + 1,ans);
            }
            
        }
        if(tree[v].r != NIL){
            if(y <= ty){
                find(tree[v].r,sx,tx,sy,ty,depth + 1,ans);
            }
        }
    }
    
}

int main(void){
    int x,y,q,root;
    cin >> N;
    
    for(int i = 0;i < N;++i){
        //cin >> x >> y;
        scanf("%d %d",&x,&y);
        point[i] = Point(i,x,y);
    }
    root = makeKDTree(0, N, 0);
    //cin >> q;
    scanf("%d",&q);
    
    int sx,sy,tx,ty;
    vector<Point>ans;
    
    for(int i = 0;i < q;++i){
        //cin >> sx >> tx >> sy >> ty;
        scanf("%d %d %d %d",&sx,&tx,&sy,&ty);
        ans.clear();
        find(root,sx,tx,sy,ty,0,ans);
        sort(ans.begin(),ans.end());
        for(int j = 0;j < ans.size();++j){
            ans[j].outPutId();
        }
        //cout << endl;
        printf("\n");
    }
}
