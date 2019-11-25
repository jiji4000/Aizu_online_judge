//
//  ITP1_5_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/04.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int i = 1;
int x;

void endCheckNum(int max);
void checkNum(int max);
void call(int max);

void endCheckNum(int max){
    if(++i <= max){
        call(max);
    }
}

void checkNum(int max){
    if(i > max){
        return;
    }
    
    x = i;
    if(x % 3 == 0){
        cout << " " << i;
        endCheckNum(max);
    }
}

void include3(int max){
    if(i > max){
        return;
    }
    
    if(x % 10 == 3){
        cout << " " << i;
        endCheckNum(max);
    }
    x /= 10;
    if(x){
        include3(max);
    }
}

void call(int max){
    checkNum(max);
    include3(max);
    endCheckNum(max);
}

int main(void){
    int num;
    cin >> num;
    call(num);
    cout << endl;
    return 0;
}
