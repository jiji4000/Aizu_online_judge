//
//  ALDS_1_4_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2018/12/07.
//  Copyright © 2018年 jiji4000. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

int main(){
    int n;
    std::string str;
    char com[9];
    std::map<std::string, int> m;

    scanf("%d",&n);
    
    for(int i = 0;i < n;++i){
        
        std::cin >> com >> str;
        if(com[0] == 'i'){
            m.insert(std::make_pair(str, i));
        }
        else if(com[0] == 'f'){
            decltype(m)::iterator it = m.find(str);
            if (it != m.end()) {
                printf("yes\n");
            }
            else{
                printf("no\n");
            }
        }
    }
    return 0;
}
