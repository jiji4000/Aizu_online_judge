//
//  DPL_3_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2020/06/03.
//  Copyright © 2020 jiji4000. All rights reserved.
//

 #include <bits/stdc++.h>
 using namespace std;
 #define MAX 1400

 struct Rectangle{
     int height;
     int pos;
 };

 int getLargestRectangle(int size,int buf[]){
     stack<Rectangle> s;
     int maxV = 0;
     buf[size] = 0;
     
     for(int i = 0;i <= size;++i){
         Rectangle rect;
         rect.height = buf[i];
         rect.pos = i;
         if(s.empty()){
             s.push(rect);
         }
         else{
             if(s.top().height < rect.height){
                 s.push(rect);
             }
             else if(s.top().height > rect.height){
                 int target = i;
                 while(!s.empty() && s.top().height >= rect.height){
                     Rectangle pre = s.top();
                     s.pop();
                     int area = pre.height * (i - pre.pos);
                     maxV = max(maxV,area);
                     target = pre.pos;
                 }
                 rect.pos = target;
                 s.push(rect);
             }
         }
     }
     return maxV;
 }

 int H,W;
 int buf[MAX][MAX];
 int T[MAX][MAX];

 int getLargestRectangle(){
     for(int j = 0;j < W;++j){
         for(int i = 0;i < H;++i){
             if(buf[i][j]){
                 T[i][j] = 0;
             }
             else{
                 T[i][j] = (i > 0) ? T[i - 1][j] + 1 : 1;
             }
         }
     }
     int maxV = 0;
     for(int i = 0;i < H;++i){
         maxV = max(maxV,getLargestRectangle(W,T[i]));
     }
     return maxV;
 }

 int main(){
     scanf("%d %d",&H,&W);
     for(int i = 0;i < H;++i){
         for(int j = 0;j < W;++j){
             scanf("%d",&buf[i][j]);
         }
     }
     printf("%d\n",getLargestRectangle());
 }
