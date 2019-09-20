//
//  ITP_1_2_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/09/20.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main(void){
    int a,b,c;
    cin >> a >> b >> c;
    
    if(a < b && b < c){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    cout << endl;
    return 0;
}
