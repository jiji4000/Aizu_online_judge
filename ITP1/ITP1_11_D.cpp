//
//  ITP1_11_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/17.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "math.h"
#include "stdio.h"

using namespace std;

#define NONE -1
#define UP_SURFACE 0
#define SURFACE 1
#define RIGHT_SURFACE 2

#define IN_ROLL 7
#define IN_PITCH 8

class Dice{
public:
    int surface[6];
    
    void roleEast();
    void roleWest();
    void roleNorth();
    void roleSouth();
    void swap(int surface2[]);
    int getSurface(int num);
    bool isPitchSide(int num);
    bool isSame(Dice dice2);
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

int Dice::getSurface(int num){
    for(int i = 0;i < 6;++i){
        if(surface[i] == num){
            return i + 1;
        }
    }
    return NONE;
}

bool Dice::isPitchSide(int num){
    int surface = getSurface(num);
    if(surface == 3 || surface == 4){
        return true;
    }
    return false;
}

bool Dice::isSame(Dice dice2){
    int upSurface =  surface[UP_SURFACE];
    int frontSurface = surface[SURFACE];
    // 存在確認
    if(dice2.getSurface(frontSurface) == NONE || dice2.getSurface(upSurface) == NONE){
        return false;
    }
    while(frontSurface != dice2.surface[SURFACE]){
        if(dice2.isPitchSide(frontSurface)){
            dice2.roleEast();
            
        }
        else {
            dice2.roleSouth();
        }
    }
    int rollNum = 0;
    // upSurfaceを合わせる
    while(upSurface != dice2.surface[UP_SURFACE]){
        dice2.roleEast();
        if(++rollNum == 4){
            return false;
        }
    }
    
    for(int i = 0;i < 6;++i){
        if(surface[i] != dice2.surface[i]){
            return false;
        }
    }
    return true;
}

int main(){
    Dice dice[100];
    int num;
    
    cin >> num;
    
    for(int i = 0;i < num;++i){
        for(int j = 0;j < 6;++j){
            cin >> dice[i].surface[j];
        }
    }
    
    for(int i = 0;i < num;++i){
        for(int j = i + 1;j < num;++j){
            if(dice[i].isSame(dice[j])){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
