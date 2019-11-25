//
//  ITP1_10_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/15.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "math.h"
#include "stdio.h"

using namespace std;

int main(){
    int n;
    double x[100],y[100];
    double man = 0,euclid = 0,p3 = 0,chbi = 0;
    cin >> n;
    
    for(int i = 0;i < 2;++i){
        for(int j = 0;j < n;++j){
            if(i == 0){
                cin >> x[j];
            }
            else{
                cin >> y[j];
            }
        }
    }
    
    for(int i = 0;i < n;++i){
        man += fabs(x[i] - y[i]);
        euclid += pow(fabs(x[i] - y[i]),2);
        p3 += pow(fabs(x[i] - y[i]),3);
        chbi = max(fabs(x[i] - y[i]),chbi);
    }
    euclid = sqrt(euclid);
    p3 = pow(p3,1.0 / 3.0);
    
    printf("%.8lf\n%.8lf\n%.8lf\n%.8lf\n",man,euclid,p3,chbi);
}
