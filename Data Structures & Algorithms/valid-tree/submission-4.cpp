class Solution {
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
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1];
            if(dsu.find(u) == dsu.find(v)) return false;
            dsu.unite(u,v);
        }
        int par = dsu.find(0);
        for(int i=0; i<n; ++i) {
            if(dsu.find(i) != par) return false;
        }
        return true;
    }
};
