//
//  ITP1_11_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/16.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "math.h"
#include "stdio.h"

using namespace std;

class Dice{
public:
    int surface[6];
    
    void roleEast();
    void roleWest();
    void roleNorth();
    void roleSouth();
    void swap(int surface2[]);
};

void Dice::swap(int* surface2){
    for(int i = 0;i < 6;++i){
        surface[i] = surface2[i];
    }
}

void Dice::roleEast(){
    int tmp[6];
    tmp[0] = surface[3];
    tmp[3] = surface[5];
    tmp[5] = surface[2];
    tmp[2] = surface[0];
    tmp[1] = surface[1];
    tmp[4] = surface[4];
    swap(tmp);
}

void Dice::roleWest(){
    int tmp[6];
    tmp[3] = surface[0];
    tmp[5] = surface[3];
    tmp[2] = surface[5];
    tmp[0] = surface[2];
    tmp[1] = surface[1];
    tmp[4] = surface[4];
    swap(tmp);
}

void Dice::roleNorth(){
    int tmp[6];
    tmp[0] = surface[1];
    tmp[1] = surface[5];
    tmp[5] = surface[4];
    tmp[4] = surface[0];
    tmp[2] = surface[2];
    tmp[3] = surface[3];
    swap(tmp);
}

void Dice::roleSouth(){
    int tmp[6];
    tmp[0] = surface[4];
    tmp[4] = surface[5];
    tmp[5] = surface[1];
    tmp[1] = surface[0];
    tmp[2] = surface[2];
    tmp[3] = surface[3];
    swap(tmp);
}

int main(){
    string s;
    Dice dice;
    for(int i = 0;i < 6;++i){
        cin >> dice.surface[i];
    }
    while(getline(cin,s)){
        for(int i = 0;i < s.length();++i){
            switch(s.at(i)){
                case 'E':
                    dice.roleEast();
                    break;
                case 'N':
                    dice.roleNorth();
                    break;
                case 'S':
                    dice.roleSouth();
                    break;
                case 'W':
                    dice.roleWest();
                    break;
            }
        }
    }
    cout << dice.surface[0] << endl;
}
