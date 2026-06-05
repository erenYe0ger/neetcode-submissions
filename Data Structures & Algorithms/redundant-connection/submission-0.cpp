class DSU {
    vector<int> size, par;
public:
    DSU(int n) {
        size.assign(n,1);
        par.resize(n);
        for(int i=0; i<n; ++i) par[i] = i;            
    }
    int find(int i) {
        if(par[i] == i) return i;
        return par[i] = find(par[i]);
    }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) return;
        if(size[u] < size[v]) swap(u,v);
        size[u] += size[v];
        par[v] = u;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        vector<int> res;
        for(auto& edge: edges) {
            int u = edge[0]-1, v = edge[1]-1;
            if(dsu.find(u) == dsu.find(v)) res = {u+1,v+1};
            else dsu.unite(u,v);
        }
        return res;
    }
};
