// 参考:http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1060290#1

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 105;
const int INF = 10001;

void visit(int V, int G[MAX][MAX], int v, int s, int r,
           vector<int> &no, vector< vector<int> > &comp,
           vector<int> &prev, vector< vector<int> > &next,
           vector<int> &mcost, vector<int> &mark,
           int &cost, bool &found) {
    if (mark[v]) {
        vector<int> temp = no;
        found = true;
        do {
            cost += mcost[v];
            v = prev[v];
            if (v != s) {
                while (comp[v].size() > 0) {
                    no[comp[v].back()] = s;
                    comp[s].push_back(comp[v].back());
                    comp[v].pop_back();
                }
            }
        } while (v != s);
        
        //REP(i, V){
        for(int i = 0;i < V;++i){
            if(i != r && no[i] == s)
                //REP(j, V){
                for(int j = 0;j < V;++j){
                    if (no[j] != s && G[j][i] < INF) G[j][i] -= mcost[temp[i]];
                }
        }
    }
    mark[v] = true;
    //REP(i, next[v].size())
    for(int i = 0;i < next[v].size();++i)
        if(no[next[v][i]] != no[v] && prev[no[next[v][i]]] == v)
            if (!mark[no[next[v][i]]] || next[v][i] == s)
                visit(V, G, next[v][i], s, r, no, comp, prev, next, mcost, mark, cost, found);
    
}

int minimumSpanningArborescence(int V, int E, int G[MAX][MAX], int r) {
    vector<int> no(V);
    vector< vector<int> > comp(V);
    for(int i = 0;i < V;++i) comp[i].push_back(no[i] = i);
    
    for(int cost = 0; ;) {
        vector<int> prev(V, -1);
        vector<int> mcost(V, INF);
        
        for(int i = 0;i < V;++i){
            for(int j = 0;j < V;++j){
                if(j == r || G[i][j] == INF || no[i] == no[j] || G[i][j] > mcost[no[j]]) continue;
                mcost[no[j]] = G[i][j];
                prev[no[j]] = no[i];
            }
        }
        vector< vector<int> > next(V);
        //REP(i, V)
        for(int i = 0;i < V;++i)
            if(prev[i] >= 0)
                next[prev[i]].push_back(i);
        
        bool stop = true;
        vector<int> mark(V, false);
        
        for(int i = 0;i < V;++i)
            if(i != r && !mark[i] && !comp[i].empty()) {
                bool found = false;
                visit(V, G, i, i, r, no, comp, prev, next, mcost, mark, cost, found);
                if (found) stop = false;
            }
        if (stop) {
            for(int i = 0;i < V;++i) if (prev[i] >= 0) cost += mcost[i];
            return cost;
        }
    }
}

int main() {
    int vNum,eNum,s;
    cin >> vNum >> eNum >> s;
    int G[MAX][MAX];
    for(int i = 0;i < vNum;++i)
        for(int j = 0;j < vNum;++j)
            G[i][j] = (i == j ? 0 : INF);
    
    for(int i = 0;i < eNum;++i){
        int v,e,w;
        cin >> v >> e >> w;
        G[v][e] = w;
    }
    cout <<minimumSpanningArborescence(vNum,eNum, G, s) <<endl;
}
