//
//  ITP2_2_A2.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/08.
//  Copyright © 2019 jiji4000. All rights reserved.
//

//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//#define MAX 1000
//
//class stack{
//    int num;
//    stack* head = NULL;
//    stack* tail = NULL;
//    bool isEmpty = true;
//public:
//    void push(int x){
//        if(isEmpty){
//            isEmpty = false;
//            num = x;
//            return;
//        }
//        if(head == NULL){
//            head = new stack(x);
//            this->tail = head;
//        }
//        else{
//            stack* tmp = head;
//            while(tmp->head != NULL){
//                tmp = tmp->head;
//            }
//            tmp->head = new stack(x);
//            this->tail = tmp->head;
//        }
//    }
//
//    int top(){
//        if(head == NULL){
//            return num;
//        }
//        else{
////            stack* tmp = head;
////            while(tmp ->head != NULL){
////                tmp = tmp->head;
////            }
////            return tmp->num;
//            return tail->num;
//        }
//    }
//
//    void pop(){
//        if(head == NULL){
//            isEmpty = true;
//        }
//        else{
//            stack* tmp = this;
//            while(tmp->head->head != NULL){
//                tmp = tmp->head;
//            }
//            this->tail = tmp;
//            delete tmp->head;
//            tmp->head = NULL;
//        }
//    }
//
//    bool empty(){
//        return isEmpty;
//    }
//
//    stack(){
//
//    }
//
//    stack(int num){
//        this->num = num;
//    }
//};
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n,q,command,t,x;
//    stack myStack[MAX];
//    cin >> n >> q;
//
//    for (int i = 0;i < q;++i) {
//        cin >> command >> t;
//        switch(command){
//                // push
//            case 0:
//                cin >> x;
//                myStack[t].push(x);
//                break;
//                // dump
//            case 1:
//                if(!myStack[t].empty()){
//                    cout << myStack[t].top() << endl;
//                }
//                break;
//                // clear
//            case 2:
//                if(!myStack[t].empty()){
//                    myStack[t].pop();
//                }
//                break;
//        }
//    }
//}


#include <iostream>

using namespace std;
#define MAX 1000

class stack{
    int num;
    stack* head = NULL;
    stack* prev = NULL;
    stack* tail = NULL;
    bool isEmpty = true;
public:
    void push(int x){
        if(isEmpty){
            isEmpty = false;
            num = x;
            return;
        }
        if(head == NULL){
            head = new stack(x);
            head->prev = this;
            this->tail = this;
        }
        else{
            stack* tmp = tail->head;
            tmp->prev = tail;
            tmp->head = new stack(x);
            tail =  tmp;
        }
    }
    
    int top(){
        if(head == NULL){
            return num;
        }
        else{
            return tail->head->num;
        }
    }
    
    void pop(){
        if(head == NULL){
            isEmpty = true;
        }
        else{
            stack* tmp = tail;
            delete tmp->head;
            tmp->head = NULL;
            tail = tail->prev;
        }
    }
    
    bool empty(){
        return isEmpty;
    }
    
    stack(){
        
    }
    
    stack(int num){
        this->num = num;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q,command,t,x;
    stack myStack[MAX];
    cin >> n >> q;
    
    for (int i = 0;i < q;++i) {
        cin >> command >> t;
        switch(command){
                // push
            case 0:
                cin >> x;
                myStack[t].push(x);
                break;
                // top
            case 1:
                if(!myStack[t].empty()){
                    cout << myStack[t].top() << endl;
                }
                break;
                // clear
            case 2:
                if(!myStack[t].empty()){
                    myStack[t].pop();
                }
                break;
        }
    }
}
