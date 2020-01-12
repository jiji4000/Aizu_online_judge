//
//  CGL_5_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2020/01/11.
//  Copyright © 2020 jiji4000. All rights reserved.
//
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

struct Point {
    double x, y;
};

bool cmpX(Point a, Point b){
    return a.x < b.x;
}

bool cmpY(Point a, Point b){
    return a.y < b.y;
}

double getDistance(Point a,Point b){
    double x = b.x - a.x;
    double y = b.y - a.y;
    return sqrt(x*x + y*y);
}

double closestPair(Point *a, int n){
    if (n == 1)  return __DBL_MAX__;
    double d = __DBL_MAX__;
    int m = n/2;
    d = min(closestPair(a,m), closestPair(a + m,n - m));
    
    double mx = a[m].x;
    vector<Point> b;
    for (int i = m;i >= 0;--i){
        double x = fabs(a[i].x - mx);
        if (x > d){
            break;
        }
        else{
            b.push_back(a[i]);
        }
    }
    for (int i = m + 1;i < n;++i){
        if (fabs(a[i].x - mx) > d){
            break;
        }
        else {
            b.push_back(a[i]);
        }
    }
    sort(b.begin(), b.end(), cmpY);
    
    for(int i = 0; i < b.size();++i){
        for(int j = i + 1;fabs(b[j].y - b[i].y) < d && j < b.size(); ++j){
            double tmp = getDistance(b[i], b[j]);
            if (tmp < d) d = tmp;
        }
    }
    return d;
}

int main(){
    int n;
    scanf("%d", &n);
    Point a[n];
    for (int i = 0; i < n; ++i){
        scanf("%lg %lf", &a[i].x, &a[i].y);
    }
    sort(a,a+n,cmpX);
    printf("%7f", closestPair(a, n));
}
