//
//  ITP2_11_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/24.
//  Copyright © 2019 jiji4000. All rights reserved.
//
#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    for(int i = 0;i < (1 << n);++i) {
        int cnt = 0;
        for (int j = 0;j < n;++j) {
            if (i & (1 << j))
                cnt++;
        }

        if(cnt == k){
            cout << i << ":";

            for (int j = 0; j < n;++j) {
                if (i & (1 << j))
                    cout << " " << j;
            }
            cout << endl;
        }
    }
}
