//
//  CGL_6_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2020/01/12.
//  Copyright © 2020 jiji4000. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

static const int BOTTOM = 0;
static const int LEFT = 1;
static const int RIGHT = 2;
static const int TOP = 3;

struct Point{
    double x;
    double y;
};

struct Segment{
    Point p1;
    Point p2;
};

class EndPoint{
public:
    Point p;
    int segId;
    int state;
    EndPoint(){};
    EndPoint(Point p,int segId,int state):p(p),segId(segId),state(state){}
    
    bool operator < (const EndPoint &ep) const {
        if(p.y == ep.p.y){
            // yが同じなら下端、左端、上端、右端で調べる
            return state < ep.state;
        }else{
            return p.y < ep.p.y;
        }
    }
};

EndPoint EP[2 * 100000];

int manhattanInterSection(vector<Segment>s){
    int n = s.size();
    
    for(int i = 0,k = 0;i < n;++i){
        // 端点p1,p2が左下に並ぶようにする
        if(s[i].p1.y == s[i].p2.y){
            if(s[i].p1.x > s[i].p2.x){
                swap(s[i].p1,s[i].p2);
            }
        }else if(s[i].p1.y > s[i].p2.y){
            swap(s[i].p1,s[i].p2);
        }
        
        if(s[i].p1.y == s[i].p2.y){
            // 水平成分を端点へ追加する
            EP[k++] = EndPoint(s[i].p1,i,LEFT);
            EP[k++] = EndPoint(s[i].p2,i,RIGHT);
        }
        else{
            // 垂直成分を端点へ追加する
            EP[k++] = EndPoint(s[i].p1,i,BOTTOM);
            EP[k++] = EndPoint(s[i].p2,i,TOP);
        }
    }
    
    // 端点のy座標に関して昇順に並び替える
    sort(EP,EP + (n * 2));
    
    set<int> BT;
    // 番兵
    BT.insert(__INT_MAX__);
    int cnt = 0;
    
    for(int i = 0;i < 2 * n;++i){
        if(EP[i].state == TOP){
            // 上端点を削除
            BT.erase(EP[i].p.x);
        } else if(EP[i].state == BOTTOM){
            // 下端点を追加
            BT.insert(EP[i].p.x);
        }else if(EP[i].state == LEFT){
            set<int>::iterator b = lower_bound(BT.begin(), BT.end(), s[EP[i].segId].p1.x);
            set<int>::iterator e = upper_bound(BT.begin(), BT.end(), s[EP[i].segId].p2.x);
            cnt += distance(b, e);
        }
    }
    return cnt;
}

int main(){
    int n;
    scanf("%d", &n);
    vector<Segment> s(n);
    for (int i = 0; i < n; ++i){
        scanf("%lf %lf %lf %lf", &s[i].p1.x,&s[i].p1.y,&s[i].p2.x, &s[i].p2.y);
    }
    int crossPointNum = manhattanInterSection(s);
    printf("%d\n", crossPointNum);
}
