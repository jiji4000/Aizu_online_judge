//
//  ITP1_11_B.cpp
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

#define UP_SURFACE 1
#define SURFACE 2
#define RIGHT_SURFACE 3

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
    return 0;
}

bool Dice::isPitchSide(int num){
    int surface = getSurface(num);
    if(surface == 3 || surface == 4){
        return true;
    }
    return false;
}


int main(){
    int num;
    Dice dice;
    int upSurface,frontSurface;
    for(int i = 0;i < 6;++i){
        cin >> dice.surface[i];
    }
    cin >> num;
    
    for(int i = 0;i < num;++i){
        cin >> upSurface >> frontSurface;
        // frontSurfaceを合わせる
        while(frontSurface != dice.surface[SURFACE - 1]){
            if(dice.isPitchSide(frontSurface)){
                dice.roleEast();
            }
            else {
                dice.roleSouth();
            }
        }
        // upSurfaceを合わせる
        while(upSurface != dice.surface[UP_SURFACE - 1]){
            dice.roleEast();
        }

        cout << dice.surface[RIGHT_SURFACE - 1] << endl;
    }
}
