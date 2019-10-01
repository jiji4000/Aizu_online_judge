//
//  ITP1_4_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/01.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int num,a;
    double sum = 0;
    cin >> num;
    
    vector<int>v;
    
    for(int i = 0;i < num;++i){
        cin >> a;
        v.push_back(a);
        sum += a;
    }
    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());
    
    cout << min << " " << max << " " << fixed << setprecision(0) << sum << endl;
    
    return 0;
}
