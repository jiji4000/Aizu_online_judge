//
//  ALDS_1_5_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/18.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <stdio.h>
#include "math.h"
#include <iostream>
using namespace std;

struct Vec2{
    double x;
    double y;
};

void kock(int n,Vec2 p1,Vec2 p2){
    if(n == 0){
        return;
    }
    Vec2 s,t,u;
    // s
    s.x = (2 * p1.x + 1 * p2.x) / 3;
    s.y = (2 * p1.y + 1 * p2.y) / 3;
    // t
    t.x = (1 * p1.x + 2 * p2.x) / 3;
    t.y = (1 * p1.y + 2 * p2.y) / 3;
    // u
    u.x = (t.x - s.x) * cos(60 * M_PI / 180) - (t.y - s.y) * sin(60 * M_PI / 180) + s.x;
    u.y = (t.x - s.x) * sin(60 * M_PI / 180) + (t.y - s.y) * cos(60 * M_PI / 180) + s.y;
    
    kock(n-1, p1, s);
    printf("%.8lf %.8lf\n",s.x,s.y);
    kock(n-1, s, u);
    printf("%.8lf %.8lf\n",u.x,u.y);
    kock(n-1, u, t);
    printf("%.8lf %.8lf\n",t.x,t.y);
    kock(n-1, t, p2);
}

int main(void){
    int n;
    cin >> n;
    Vec2 p1 = {0,0},p2 = {100,0};
    printf("%.8lf %.8lf\n",p1.x,p1.y);
    kock(n,p1,p2);
    printf("%.8lf %.8lf\n",p2.x,p2.y);
}
