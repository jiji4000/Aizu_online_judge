//
//  ITP1_8_D.cpp
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
    string str;
    string str2;
    int firstIndex[100];
    int firstNum = 0;
    cin >> str >> str2;
    
    for(int i = 0;i < str.length();++i){
        if(str.at(i) == str2.at(0)){
            firstIndex[firstNum] = i;
            firstNum++;
        }
    }
    
    for(int i = 0;i < firstNum;++i){
        int index = firstIndex[i];
        
        for(int j = 0;j < str2.length();++j){
            if(str.at(index) != str2.at(j)){
                break;
            }
            if(++index >= str.length()){
                index = 0;
            }
            if(j + 1 >= str2.length()){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
