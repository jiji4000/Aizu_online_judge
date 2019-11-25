//
//  ITP1_1_C.cpp
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
    int width,height;
    cin >> width >> height;

    int area = width * height;
    int perimeter = (width * 2) + (height * 2);
    cout << area << " " << perimeter << endl;
    return 0;
}
