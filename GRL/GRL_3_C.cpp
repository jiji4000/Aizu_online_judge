// 参考:https://ei1333.github.io/luzhiled/snippets/graph/strongly-connected-components.html

#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct edge {
    int src, to;
    int cost;
    
    edge(int to, int cost) : src(-1), to(to), cost(cost) {}
    
    edge(int src, int to, int cost) : src(src), to(to), cost(cost) {}
    
    edge &operator=(const int &x) {
        to = x;
        return *this;
    }
    
    operator int() const { return to; }
};

struct StronglyConnectedComponents {
    const vector<vector<int>> &g;
    vector<vector<int>> gg, rg;
    vector<int> comp, order, used;
    
    StronglyConnectedComponents(vector<vector<int> > &g) : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1), used(g.size()) {
        for(int i = 0; i < g.size(); i++) {
            for(auto e : g[i]) {
                gg[i].emplace_back((int) e);
                rg[(int) e].emplace_back(i);
            }
        }
    }
    
    int operator[](int k) {
        return comp[k];
    }
    
    void dfs(int idx) {
        if(used[idx]) return;
        used[idx] = true;
        for(int to : gg[idx]) dfs(to);
        order.push_back(idx);
    }
    
    void rdfs(int idx, int cnt) {
        if(comp[idx] != -1) return;
        comp[idx] = cnt;
        for(int to : rg[idx]) rdfs(to, cnt);
    }
    
    void build(vector<vector<int>> &t) {
        for(int i = 0; i < gg.size(); i++) dfs(i);
        reverse(begin(order), end(order));
        int ptr = 0;
        for(int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;
        
        t.resize(ptr);
        for(int i = 0; i < g.size(); i++) {
            for(auto &to : g[i]) {
                int x = comp[i], y = comp[to];
                if(x == y) continue;
                t[x].push_back(y);
            }
        }
    }
};

int main() {
    int v,e,q;
    scanf("%d %d", &v, &e);
    vector<vector<int>> g(v), buff;
    
    for(int i = 0;i < e;++i) {
        int u,v;
        scanf("%d %d", &u, &v);
        g[u].emplace_back(v);
    }
    
    StronglyConnectedComponents scc(g);
    scc.build(buff);
    scanf("%d", &q);
    while(q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        puts(scc[u] == scc[v] ? "1" : "0");
    }
}// 参考:https://ei1333.github.io/luzhiled/snippets/graph/strongly-connected-components.html

#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct edge {
    int src, to;
    int cost;
    
    edge(int to, int cost) : src(-1), to(to), cost(cost) {}
    
    edge(int src, int to, int cost) : src(src), to(to), cost(cost) {}
    
    edge &operator=(const int &x) {
        to = x;
        return *this;
    }
    
    operator int() const { return to; }
};

struct StronglyConnectedComponents {
    const vector<vector<int>> &g;
    vector<vector<int>> gg, rg;
    vector<int> comp, order, used;
    
    StronglyConnectedComponents(vector<vector<int> > &g) : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1), used(g.size()) {
        for(int i = 0; i < g.size(); i++) {
            for(auto e : g[i]) {
                gg[i].emplace_back((int) e);
                rg[(int) e].emplace_back(i);
            }
        }
    }
    
    int operator[](int k) {
        return comp[k];
    }
    
    void dfs(int idx) {
        if(used[idx]) return;
        used[idx] = true;
        for(int to : gg[idx]) dfs(to);
        order.push_back(idx);
    }
    
    void rdfs(int idx, int cnt) {
        if(comp[idx] != -1) return;
        comp[idx] = cnt;
        for(int to : rg[idx]) rdfs(to, cnt);
    }
    
    void build(vector<vector<int>> &t) {
        for(int i = 0; i < gg.size(); i++) dfs(i);
        reverse(begin(order), end(order));
        int ptr = 0;
        for(int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;
        
        t.resize(ptr);
        for(int i = 0; i < g.size(); i++) {
            for(auto &to : g[i]) {
                int x = comp[i], y = comp[to];
                if(x == y) continue;
                t[x].push_back(y);
            }
        }
    }
};

int main() {
    int v,e,q;
    scanf("%d %d", &v, &e);
    vector<vector<int>> g(v), buff;
    
    for(int i = 0;i < e;++i) {
        int u,v;
        scanf("%d %d", &u, &v);
        g[u].emplace_back(v);
    }
    
    StronglyConnectedComponents scc(g);
    scc.build(buff);
    scanf("%d", &q);
    while(q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        puts(scc[u] == scc[v] ? "1" : "0");
    }
}
