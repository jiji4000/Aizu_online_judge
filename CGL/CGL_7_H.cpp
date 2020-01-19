//
//  CGL_7_H.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2020/01/19.
//  Copyright © 2020 jiji4000. All rights reserved.
//

#include <iostream>
#include <complex>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
typedef complex<double> P;
typedef pair<P,P> L;
typedef pair<P,double> C;
typedef vector<P> Poly;
#define X real()
#define Y imag()
const double EPS = (1e-10), pi = acos(-1);

//2D version

double dot(P a, P b){ return a.X * b.X + a.Y * b.Y;}
double cross(P a, P b){ return a.X * b.Y - a.Y * b.X;}

P projection(P a, P b){ return dot(a, b)/abs(b)/abs(b)*b;}

P intersection(L a, L b){
    //直線aと直線bの交点
    P af = a.first, as = a.second, bf = b.first, bs = b.second;
    return af + cross(bs-bf,af-bf)/(-cross(bs-bf,as-bf)+cross(bs-bf,af-bf))*(as-af);
}

int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if(cross(b,c) > EPS) return +1;
    if(cross(b,c) < -EPS) return -1;
    if(dot(b,c) < 0) return +2;
    if(abs(b) + EPS < abs(c)) return -2;
    return 0;
}

double ps_dist(P a, L s){
    P sf = s.first, ss = s.second;
    if(dot(ss-sf,a-sf) >= 0 && dot(sf-ss,a-ss) >= 0)
        return abs(cross(sf-ss,a-ss))/abs(sf-ss);
    return min(abs(a-sf), abs(a-ss));
}

double pl_dist(P a, L s){
    P sf = s.first, ss = s.second;
    return abs(cross(sf-ss,a-ss))/abs(sf-ss);
}


vector<P> cpcl(C c, L l){
    //円cと直線lの交点
    //接する場合は同一の点を二つ返す
    double d = pl_dist(c.first,l), r = c.second;
    P m = l.first + projection(c.first-l.first,l.second-l.first);
    P x = sqrt(r*r-d*d)/abs(l.second-l.first)*(l.second-l.first);
    vector<P> cp(2,m);
    cp[0] -= x;
    cp[1] += x;
    return cp;
}

double common_area_cp(C c, Poly p){
    //円と非凸多角形の共通面積
    double ret = 0, r = c.second;
    int n = p.size();
    for(int i = 0; i < n; ++i) p[i] -= c.first;
    for(int i = 0; i < n; ++i){
        if(abs(p[i]*p[(i+1)%n]) < EPS) continue;
        double d = arg(p[(i+1)%n]/p[i]);
        ret += r*r*d/2.0;
        if(ps_dist(P(0,0),L(p[i],p[(i+1)%n])) < r - EPS){
            vector<P> cps = cpcl(C(P(0,0),r),L(p[i],p[(i+1)%n]));
            P a, b;
            if(ccw(p[i],p[(i+1)%n],cps[0]) == 0 &&
               ccw(p[i],p[(i+1)%n],cps[1]) == 0)
                a = cps[0], b = cps[1];
            else if(!ccw(p[i],p[(i+1)%n],cps[0]))
                a = cps[0], b = p[(i+1)%n];
            else if(!ccw(p[i],p[(i+1)%n],cps[1]))
                a = p[i], b = cps[1];
            else
                a = p[i], b = p[(i+1)%n];
            if(abs(a*b) < EPS) continue;
            d = arg(b/a);
            ret += cross(a,b)/2.0 - r*r*d/2.0;
        }
    }
    return ret;
}

int main(){
    int n;
    double r;
    cin >> n >> r;
    Poly Pol;
    C c(P(0,0),r);
    for(int i = 0; i < n; ++i){
        double x, y;
        cin >> x >> y;
        Pol.emplace_back(x,y);
    }
    double ans = common_area_cp(c,Pol);
    printf("%.12f\n",ans);
    return 0;
}
