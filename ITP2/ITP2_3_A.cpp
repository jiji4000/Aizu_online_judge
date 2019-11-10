//
//  ITP2_3_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/10.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    cout << a[0] << " " << a[2] << endl;
}
