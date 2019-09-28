//
//  ITP1_3_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/09/28.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(void){
    int a,b,c,num = 0;
    
    cin >> a >> b >> c;

    for(int i = a;i <= b;++i){
        if(c % i == 0){
            num++;
        }
    }
    cout << num << endl;

    return 0;
}

