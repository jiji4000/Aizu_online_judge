//
//  ITP1_9_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/13.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    int num,point[2] = {};
    string str1,str2;
    
    cin >> num;
    
    for(int i = 0;i < num;++i){
        cin >> str1 >> str2;
        
        
        if(str1 == str2){
            point[0]++;
            point[1]++;
        }
        else{
            long min1 = min(str1.length(),str2.length());
            for(int j = 0;j < min1;++j){
                if(str1.at(j) == str2.at(j)){
                    
                }
                else if(str1.at(j) == max(str1.at(j),str2.at(j))){
                    point[0] += 3;
                    break;
                }
                else if(str2.at(j) == max(str1.at(j),str2.at(j))){
                    point[1] += 3;
                    break;
                }
                
                // 最後まで同じ文字だった場合
                if(j + 1 >= min1){
                    // 文字数が多いほうがwin
                    if(str1.length() > str2.length()){
                        point[0] += 3;
                    }
                    else {
                        point[1] += 3;
                    }
                }
            }
        }
    }
    cout << point[0] << " " << point[1] << endl;
}
