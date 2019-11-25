//
//  ITP1_1_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/09/19.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main(void){
    int input;
    cin >> input;
    
    int hour = input / 3600;
    input -= hour * 3600;
    
    // mininutes
    int minites = input / 60;
    input -= minites * 60;
    
    // seconds
    int seconds = input;
    
    cout << hour << ":" << minites << ":" << seconds << endl;
    return 0;
}
