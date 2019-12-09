//
//  DSL_3_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/12/09.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    int n,q,right;
    ll sum,ans;
    cin >> n >> q;
    vector<ll> a(n),x(q);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < q; ++i) {
        cin >> x[i];
    }
    
    for(int i = 0; i < q; ++i) {
        right = sum = ans = 0;

        for (int left = 0;left < n;++left) {
            while (right < n && sum + a[right] <= x[i]) {
                sum += a[right];
                ++right;
            }
            ans += (right - left);
            if (right == left){
                ++right;
            }else{
              sum -= a[left];
            }
        }
        cout << ans << endl;
    }
}
