//
//  DSL_3_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/12/07.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n,k,cnt = 0,j = 0,len = __INT_MAX__;
    cin >> n >> k;
    int a[n],ans[n],flag[n + 1];
    for(int i = 0;i < n;++i){
        cin >> a[i];
        ans[i] = flag[i] = 0;
    }
    flag[n] = 0;
    
    for(int i = 0;i < n;++i){
        flag[a[i]]++;
        if(flag[a[i]] == 1 && a[i] <= k){
            cnt++;
        }
        if(cnt < k){
            ans[i] = 0;
        }else{
            while(flag[a[j]] >= 2 || a[j] > k){
                flag[a[j]]--;
                j++;
            }
            ans[i] = i - j + 1;
        }
    }
    
    for(int i = 0;i < n;++i){
        if(ans[i] != 0){
            len = min(len, ans[i]);
        }
    }
    if(len == __INT_MAX__){
        len = 0;
    }
    cout << len << endl;
}
