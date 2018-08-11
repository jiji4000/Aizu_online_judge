//
//  ITP2_1_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2018/08/11.
//  Copyright © 2018年 jiji4000. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int>vec;
    vector<int> output;
    int size;
    int firstNum;
    int secondNum = 0;
    
    cin >> size;

    for(int i = 0;i < size;++i){
        cin >> firstNum;
        if(firstNum != 2){
            cin >> secondNum;
        }
        switch (firstNum) {
            case 0:
                vec.push_back(secondNum);
                break;
            case 1:
                output.push_back(vec.at(secondNum));
                break;
            default:
                vec.pop_back();
                break;
        }
    }
    for(int i = 0;i < output.size();++i){
        printf("%d\n",output.at(i));
        if(i + 1 > output.size()){
            printf("\n");
        }
    }
    return 0;
}
