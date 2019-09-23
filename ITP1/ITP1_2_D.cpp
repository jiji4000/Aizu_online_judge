//
//  ITP1_2_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/09/20.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct Vec2{
    int x;
    int y;
    
    Vec2(int x1,int y1){
        x = x1;
        y = y1;
    }
    Vec2(){
        
    }
};

struct Line{
    // vector2D
    Vec2 base;
    // vector2D
    Vec2 direction;
};

float getlengthLineBetweenPoint(float a,float b,float c,Vec2 point){
    // 点と直線の距離の公式に当てはめる
    return abs((a * point.x + b * point.y + c) / sqrt((a * a) + (b * b)));
}

int main(void){
    int width,height,centerX,centerY,radius;
    cin >> width >> height >> centerX >> centerY >> radius;
    
    // 原点を通る縦直線(x = 0)
    float distance1 = getlengthLineBetweenPoint(1,0,0,Vec2(centerX,centerY));
    // 原点を通る横直線(y = 0)
    float distance2 = getlengthLineBetweenPoint(0,1,0,Vec2(centerX,centerY));
    // 縦直線
    float distance3 = getlengthLineBetweenPoint(1,0,-width,Vec2(centerX,centerY));
    // 横直線
    float distance4 = getlengthLineBetweenPoint(0,1,-height,Vec2(centerX,centerY));
    
    string str = "No";
    // 円の半径の距離が全ての直線との距離未満ならばぶつかっていないことになる
    // 円と直線がぶつかっていない
    if(distance1 >= radius && distance2 >= radius && distance3 >= radius && distance4 >= radius){
        // かつ円の中心が四角形の内部になる
        // x座標
        if(centerX > 0 && centerX < width){
            // y座標
            if(centerY > 0 && centerY < height){
                str = "Yes";
            }
        }
    }
    cout << str << endl;
    
    return 0;
}

