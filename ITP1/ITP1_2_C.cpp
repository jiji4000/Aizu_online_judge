//
//  ITP1_2_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/09/20.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(void){
    int nums[3];
    cin >> nums[0] >> nums[1] >> nums[2];
    std::sort(nums,3 + nums);
    
    cout << nums[0] << " " << nums[1] << " " << nums[2] << endl;
    return 0;
}
