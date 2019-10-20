//
//  ALDS1_3_D.cpp
//  AizuOnlineJudge
//
//  Created by 佐藤俊一朗 on 2019/10/19.
//  Copyright © 2019年 jiji4000. All rights reserved.
//
#include <stdio.h>
#include <iostream>

using namespace std;

#define NONE -1

int checkLength(int index,string str){
    int height = 1;
    for(int i = index;i < str.length();++i){
        switch(str.at(i)){
            case '\\':
                height++;
                break;
            case '_':
                break;
            case '/':
                height--;
                if(height == 0){
                    return i;
                }
                break;
        }
    }
    return NONE;
}

float checkArea(int index1,int index2,string s){
    int height = 1;
    float area = 0.5;
    
    for(int i = index1;i <= index2;++i){
        switch(s.at(i)){
            case '\\':
                area += 0.5 + height;
                height++;
                break;
            case '_':
                area += height;
                break;
            case '/':
                height--;
                area += 0.5 + height;
                break;
        }
    }
    return area;
}


int main(void){
    string s;
    int poolNum = 0;
    double area[20000] = {};
    double totalArea = 0;
    cin >> s;
    
    for(int i = 0;i < s.length();++i){
        if(s.at(i) == '\\'){
            int length = checkLength(i + 1, s);
            if(length != NONE){
                area[poolNum] = checkArea(i + 1,length, s);
                totalArea += area[poolNum];
                poolNum++;
                i = length;
            }
        }
    }
    printf("%.0lf\n",totalArea);
    //cout << totalArea << endl;
    cout << poolNum;
    if(poolNum > 0){
        cout << " ";
    }
    else{
        cout << endl;
    }
    
    for(int i = 0;i < poolNum;++i){
        //cout << area[i];
        printf("%.0lf",area[i]);
        if(i + 1 >= poolNum){
            cout << endl;
        }
        else{
            cout << " ";
        }
    }
}


