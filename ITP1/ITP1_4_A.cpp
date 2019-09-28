//
//  ITP_1_4_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/09/28.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

using namespace std;

int main(void){
    int a,b;
    
    cin >> a >> b;
    
    int d,r;
    double f;
    
    d = a / b;
    r = a % b;
    f = (double)a /  b;
    
    cout << d << " " << r << " " << fixed << setprecision(5) << f << endl;
    
    return 0;
}

