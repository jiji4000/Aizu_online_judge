//
//  ITP1_10_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/14.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include "math.h"
#include "stdio.h"

using namespace std;

int main(){
    int n;
    double m,a = 0,sum = 0;
    int score[1000];
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        a = 0;
        sum = 0;
        for(int i = 0;i < n;++i){
            cin >> score[i];
            sum += score[i];
        }
        m = sum / n;
        for(int i = 0;i < n;++i){
            a += (score[i] - m) * (score[i] - m) / n;
        }
        a = sqrt(a);
        printf("%.8lf\n",a);
    }
}
