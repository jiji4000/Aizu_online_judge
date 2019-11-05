//
//  ALDS1_15_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/05.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include<iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int table[4] = {25,10,5,1},index = 0,num = 0;
    unsigned long input;
    cin >> input;
    
    while(1){
        if(input >= table[index]){
            int tmp = input / table[index];
            num += tmp;
            input -= tmp * table[index];
            if(input <= 0){
                break;
            }
        }
        ++index;
    }
    cout << num << endl;
}
