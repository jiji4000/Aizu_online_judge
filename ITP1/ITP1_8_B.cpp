//
//  ITP1_8_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/11.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void){
    string str[1000];
    int num = 0;
    
    while(1){
        cin >> str[num];
        if(str[num].at(0) == '0'){
            break;
        }
        ++num;
    }
    for(int i = 0;i < num;++i){
        int sum = 0;
        for(int j = 0;j < str[i].length();++j){
            sum += str[i].at(j) - '0';
        }
        cout << sum << endl;
    }
}
