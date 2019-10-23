//
//  ALDS1_15_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/23.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100000

int main(void){
    int num;
    pair<int,int> times[MAX];
    cin >> num;
    
    for(int i = 0;i < num;++i){
        // firstに終了時間をsecondに開始時間を入れる
        cin >> times[i].second >> times[i].first;
    };
    
    sort(times,times + num);
    
    int ans = 0,t = -1;
    for(int i = 0;i < num;++i){
        // 終了時間が最も早いものを選び続ける
        if(t < times[i].second){
            ++ans;
            t = times[i].first;
        }
    }
    cout << ans << endl;
}
