//
//  ITP1_9_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/12.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main(){
    string str1,str2;
    cin >> str1;
    int num = 0;
    regex re("^" + str1 + "$" , regex_constants::icase);
    smatch m;
    
    while(1){
        cin >> str2;
        if(str2.find("END_OF_TEXT") != string::npos){
            break;
        }
        if(std::regex_search(str2, m, re)){
            ++num;
        }
    }
    cout << num << endl;
    return 0;
}
