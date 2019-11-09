
//
//  ITP2_2_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/09.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>

using namespace std;
#define MAX 1000

class queue{
    int num;
    queue* head = NULL;
    queue* tail = NULL;
public:
    void enque(int x){
        if(head == NULL){
            head = new queue(x);
            tail = head;
        }
        else{
            tail->head = new queue(x);
            tail = tail->head;
        }
    }
    
    int front(){
        return head->num;
    }
    
    void deque(){
        // 繋ぎかえる
        if(this->head->head != NULL){
            queue* tmp = head;
            this->head = this->head->head;
            delete tmp;
            tmp = NULL;
        }
        else if(head != NULL){
            delete head;
            head = NULL;
        }
    }
    
    bool empty(){
        return head == NULL;
    }
    
    queue(){
        
    }
    
    queue(int num){
        this->num = num;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q,command,t,x;
    queue myQueue[MAX];
    cin >> n >> q;
    
    for (int i = 0;i < q;++i) {
        cin >> command >> t;
        switch(command){
                // enque
            case 0:
                cin >> x;
                myQueue[t].enque(x);
                break;
                // front
            case 1:
                if(!myQueue[t].empty()){
                    cout << myQueue[t].front() << endl;
                }
                break;
                // deque
            case 2:
                if(!myQueue[t].empty()){
                    myQueue[t].deque();
                }
                break;
        }
    }
}
