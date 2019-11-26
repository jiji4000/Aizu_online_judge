//
//  DSL_1_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/26.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class WeightedDisjointSet{
public:
    vector<int> p,rank,depth;
    
    WeightedDisjointSet();
    WeightedDisjointSet(int size){
        // サイズをセットし直す
        rank.resize(size,0);
        p.resize(size,0);
        depth.resize(size,0);
        for(int i = 0;i < size;++i){
            makeSet(i);
        }
    }
    
    // 要素xがただ一つである集合を作る
    void makeSet(int x){
        p[x] = x;
        rank[x] = 0;
        depth[x] = 0;
    }
    
    // 同じ集合にいるか
    bool same(int x,int y){
        return findSet(x) == findSet(y);
    }
    
    void relate(int x, int y, int z){
        int px = findSet(x);
        int py = findSet(y);
        link(px,py,depth[y] + z - depth[x]);
    }
    
    // 要素xが属する集合の代表の要素を求める
    int findSet(int x){
        // 自身がルートでない場合
        if(x != p[x]){
            // 自身の親をさかのぼる
            int tmp = findSet(p[x]);
            depth[x] += depth[p[x]];
            p[x] = tmp;
        }
        return p[x];
    }
    
    void link(int x, int y, int z){
        if(rank[x] > rank[y]){
            p[y] = x;
            depth[y] = -z;
        }else{
            p[x] = y;
            depth[x] = z;
            if(rank[x] == rank[y]){
                rank[y]++;
            }
        }
    }

    int diff(int x, int y){
        return sumDepth(x) - sumDepth(y);
    }
    
    int sumDepth(int x){
        int sum = 0;
        int index = x;
        while(index != p[index]){
            sum += depth[index];
            index = p[index];
        }
        return sum;
    }
};

int main(void){
    int n,q,c,x,y,z;
    cin >> n >> q;
    WeightedDisjointSet wds = WeightedDisjointSet(n);
    
    for(int i = 0;i < q;++i){
        cin >> c >> x >> y;
        switch(c){
                // relate
            case 0:{
                cin >> z;
                wds.relate(x, y, z);
                break;
            }
                // diff
            case 1:{
                if(!wds.same(x, y)){
                    cout << "?" << endl;
                }
                else{
                    cout << wds.diff(x, y) << endl;
                }
                break;
            }
        }
    }
}
