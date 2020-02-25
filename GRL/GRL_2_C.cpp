#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> G[1000000];
vector<int> articulation;
int ord[1000000], low[1000000];
bool vis[1000000];

void dfs(int v, int p, int &k)
{
    vis[v] = true;
    ord[v] = k++;
    low[v] = ord[v];
    
    bool isArticulation = false;
    int ct = 0;
    
    for (int i = 0; i < G[v].size(); i++){
        if (!vis[G[v][i]]){
            ct++;
            dfs(G[v][i], v, k);
            low[v] = min(low[v], low[G[v][i]]);
            if (~p && ord[v] <= low[G[v][i]]) isArticulation = true;
        }
        else if (G[v][i] != p){
            low[v] = min(low[v], ord[G[v][i]]);
        }
    }
    
    if (p == -1 && ct > 1) isArticulation = true;
    if (isArticulation) articulation.push_back(v);
}

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0;i < m;++i){
        int v, e;
        scanf("%d %d",&v,&e);
        G[v].push_back(e);
        G[e].push_back(v);
    }
    int k = 0;
    for (int i = 0; i < n; i++){
        if (!vis[i]) dfs(i, -1, k);
    }
    sort(articulation.begin(), articulation.end());
    for (int i = 0; i < articulation.size(); i++)
        printf("%d\n", articulation[i]);
}
