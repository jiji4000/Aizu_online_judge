//
//  ITP1_11_C.cpp
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

int main(){
    Dice dice[2];
    int rollNum = 0;
    
    for(int i = 0;i < 6;++i){
        cin >> dice[0].surface[i];
    }
    for(int i = 0;i < 6;++i){
        cin >> dice[1].surface[i];
    }
    
    int upSurface = dice[0].surface[UP_SURFACE];
    int frontSurface = dice[0].surface[SURFACE];
    
    cin >> upSurface >> frontSurface;
    // frontSurfaceを合わせる
    if(dice[1].getSurface(frontSurface) == NONE || dice[1].getSurface(upSurface) == NONE){
        cout << "No" << endl;
    }
    while(frontSurface != dice[1].surface[SURFACE]){
        if(dice[1].isPitchSide(frontSurface)){
            dice[1].roleEast();
        
        }
        else {
            dice[1].roleSouth();
        }
    }
    rollNum = 0;
    // upSurfaceを合わせる
    while(upSurface != dice[1].surface[UP_SURFACE]){
        dice[1].roleEast();
    }
    
    for(int i = 0;i < 6;++i){
        if(dice[0].surface[i] != dice[1].surface[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
}

