//
//  PlacingMarbles.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/08/13.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0;i < 3;++i){
        if(s.at(i) == '1'){
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}
