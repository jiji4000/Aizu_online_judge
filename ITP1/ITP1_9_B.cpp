//
//  ITP1_9_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/12.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    string str1,str2;
    int num,index;
    while(1){
        cin >> str1;
        if(str1.at(0) == '-'){
            return 0;
        }
        cin >> num;
        for(int i = 0;i < num;++i){
            cin >> index;
            str2 = str1.substr(0,index);
            str1.erase(0,index);
            str1 = str1 + str2;
        }
        cout << str1 << endl;
    }
}
