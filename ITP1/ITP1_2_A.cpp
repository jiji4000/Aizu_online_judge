//
//  ITP1_2_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/09/19.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main(void){
    int a,b;
    cin >> a >> b;
    
    string symbol;
    
    if(a > b){
        symbol = " > ";
    }
    else if(a < b){
        symbol = " < ";
    }
    else{
        symbol = " == ";
    }

    cout << "a" << symbol << "b" << endl;
    
    return 0;
}
