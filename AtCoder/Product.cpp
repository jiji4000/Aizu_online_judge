//
//  Product.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/08/13.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int c = a * b;
    string ans = c % 2 == 0 ? "Even" : "Odd";
    
    cout << ans << endl;
    return 0;
}
