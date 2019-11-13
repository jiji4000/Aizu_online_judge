//
//  ITP2_5_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/13.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include<iostream>
#include<algorithm>
using namespace std;

struct object{
    int v,w;
    char t;
    unsigned long d;
    string s;
    
    bool operator < (const object &o) const {
        // 価値
        if(v != o.v){
            return v < o.v;
        }
        else {
            // 重さ
            if(w != o.w){
                return w < o.w;
            }
            else{
                // 型 char
                if(t != o.t){
                    return t < o.t;
                }
                else{
                    // 日時 unsinged long
                    if(d != o.d){
                        return d < o.d;
                    }
                    else{
                        // 名前 string
                        if(s != o.s){
                            return lexicographical_compare(s.begin(),s.end(),o.s.begin(),o.s.end());
                        }
                    }
                }
            }
        }
        return false;
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    object o[n];

    for(int i = 0;i < n;++i){
        cin >> o[i].v >> o[i].w >> o[i].t >> o[i].d >> o[i].s;
    }

    sort(o,o + n);

    for(int i = 0;i < n;++i){
        cout << o[i].v << " " << o[i].w << " " << o[i].t << " " <<  o[i].d << " " << o[i].s << endl;
    }
}
