//
//  DSL_3_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/12/07.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
typedef long long ll;
using namespace std;

int main()
{
    int n, s,ans,cnt = 0;
    ll sum = 0;
    cin >> n >> s;
    int a[100001];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(sum < s){
            sum += a[i];
            ++cnt;
        }
    }

    if(sum < s){
        cout << "0" << endl;
        return 0;
    }
    ans = cnt;
    for(int i = 1;i < n;++i){
        sum -= a[i - 1];
        cnt--;
        while(i + cnt < n && sum < s){
            sum += a[i + cnt];
            cnt++;
        }
        if(sum >= s){
            ans = min(ans, cnt);
        }
    }
    cout << ans << endl;
}
