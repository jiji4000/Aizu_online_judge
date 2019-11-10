//
//  ITP2_3_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/10.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

static const int N = 1000;

int main(){
    int n,commandNum,a[N],b,c,d;
    cin >> n;
    for(int i = 0;i < n;++i){
        cin >> a[i];
    }
    cin >> commandNum;
    
    for(int i = 0;i < commandNum;++i){
        cin >> b >> c >> d;
        switch(b){
                // min
            case 0:
                cout << *min_element(a + c,a + d) << endl;
                break;
                // max
            case 1:
                cout << *max_element(a + c,a + d) << endl;
                break;
        }
    }
}
