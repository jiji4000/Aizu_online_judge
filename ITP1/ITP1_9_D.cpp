//
//  ITP1_9_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/13.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int num,a,b;
    string str1,str2,str3;
    cin >> str1 >> num;
    
    for(int i = 0;i < num;++i){
        cin >> str2;
        if(str2 == "replace"){
            cin >> a >> b >> str3;
            str1.replace(a, (b - a) + 1, str3);
        }else if(str2 == "reverse"){
            cin >> a >> b;
            string tmp = str1.substr(a,(b - a) + 1);
            reverse(tmp.begin(), tmp.end());
            str1.erase(a,(b - a) + 1);
            str1.insert(a, tmp);
        }else if(str2 == "print"){
            cin >> a >> b;
            cout << str1.substr(a,(b - a) + 1) << endl;
        }
    }
}
