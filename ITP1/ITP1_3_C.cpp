//
//  ITP1_3_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/09/26.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;
pair<int,int> pairs[3000];

int main(void){
    int index = 0;
    while(1){
        cin >> pairs[index].first >> pairs[index].second;
        if(pairs[index].first == 0 && pairs[index].second == 0){
            break;
        }
        ++index;
    }
    
    for(int i = 0;i < index;++i){
        // 並び替え
        if(pairs[i].first > pairs[i].second){
            int tmp = pairs[i].first;
            pairs[i].first = pairs[i].second;
            pairs[i].second = tmp;
        }
        cout << pairs[i].first << " " << pairs[i].second << endl;
    }
    
    return 0;
}
