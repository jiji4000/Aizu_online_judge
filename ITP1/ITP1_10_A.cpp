//
//  ITP1_10_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/14.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include "math.h"
#include "stdio.h"
//#include <cstdlib>
using namespace std;

int main(){
    double point[4],x,y,d;
    for(int i = 0;i < 4;++i){
        cin >> point[i];
    }
    x = fabs(point[2] - point[0]);
    y = fabs(point[3] - point[1]);
    d = sqrt(pow(x,2) + pow(y,2));
    printf("%.8lf\n",d);
}
