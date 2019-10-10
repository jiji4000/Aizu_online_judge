//
//  ITP1_8_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/10.
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
    std::getline(std::cin, str);

    for(int i = 0;i < str.length();++i){
        char c = str.at(i);
        if(c >= 'a' && c <= 'z'){
            str.at(i) = c - 0x20;
        }else if(c >= 'A' && c <= 'Z'){
            str.at(i) = c + 0x20;
        }
    }
    cout << str << endl;
    return 0;
}
