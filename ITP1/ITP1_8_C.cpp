//
//  ITP1_8_C.cpp
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
    int nums[26] = {};
    while(getline(cin,str)){
        for(int i = 0;i < str.length();++i){
            char c = str.at(i);
            if(islower(c)){
                int a = c - 97;
                nums[a]++;
            }
            else if(isupper(c)){
                int a = c + 32 - 97;
                nums[a]++;
            }
        }
    }

    for(int i = 0;i < 26;++i){
        cout << char('a' + i) << " : " << nums[i] << endl;
    }
}
