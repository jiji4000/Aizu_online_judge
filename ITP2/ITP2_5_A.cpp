//
//  ITP2_5_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/12.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include<iostream>
#include<algorithm>
using namespace std;

struct object{
    int x,y;

    bool operator < (const object &o) const {
        if(x != o.x){
            return x < o.x;
        }
        else {
            return y < o.y;
        }
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    object o[n];
    
    for(int i = 0;i < n;++i){
        cin >> o[i].x >> o[i].y;
    }

    sort(o,o + n);

    for(int i = 0;i < n;++i){
        cout << o[i].x << " " << o[i].y << endl;
    }
}
