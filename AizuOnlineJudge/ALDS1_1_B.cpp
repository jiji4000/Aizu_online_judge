//
//  ALDS1_1_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/08/05.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <algorithm>
#include <stdio.h>

using namespace std;

int gcd(int x,int y){
    int r;
    if(x < y){
        // 入れ替え
        swap(x,y);
    }
    
    while(y > 0){
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d\n",gcd(x,y));
    return 0;
}
