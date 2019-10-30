//
//  ALDS1_14_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/29.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    string str1,str2;
    unsigned long index = 0;
    
    cin >> str1 >> str2;
    
    while(1){
        unsigned long tmp = str1.find(str2,index);
        if(tmp == string::npos){
            break;
        }
        else{
            cout << tmp << endl;
            index = tmp + 1;
        }
    }
}
