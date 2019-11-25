//
//  ITP1_4_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/09/29.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

using namespace std;

int main(void){
    double r;
    cin >> r;
    
    double s = M_PI * (r * r);
    double circumference = 2 * M_PI * r;
    
    cout << fixed << setprecision(6) << s << " " << circumference << endl;
    
    return 0;
}

