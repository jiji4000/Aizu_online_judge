#include <vector>
#include <iostream>
using namespace std;
#define MAX 100000

struct edge{
    int s,t,d;
};

vector<edge> edges;
int d[MAX];

void BellmanFord(int startVertex,int vNum,int eNum){
    fill(d,d + MAX,__INT_MAX__);
    d[startVertex] = 0;
    
    for(int i=0;i < vNum;++i){
        bool update = false;
        for(int j = 0;j < eNum;++j){
            edge e = edges[j];
            if(d[e.s] != __INT_MAX__ && d[e.t] > d[e.s] + e.d){
                d[e.t] = d[e.s] + e.d;
                update = true;
                if(i == vNum - 1){
                    cout<<"NEGATIVE CYCLE"<<endl;
                    return;
                }
            }
        }
        if(!update)break;
    }
    for(int i = 0;i < vNum;++i){
        if(d[i]==__INT_MAX__){
            cout << "INF"<< endl;
        }
        else cout<< d[i] << endl;
    }
}

int main(){
    int v,e,r;
    cin >> v >> e >> r;
    for(int i = 0;i < e;++i){
        int s,t,d;
        cin >> s >> t >> d;
        edges.push_back({s,t,d});
    }
    BellmanFord(r,v,e);
}

