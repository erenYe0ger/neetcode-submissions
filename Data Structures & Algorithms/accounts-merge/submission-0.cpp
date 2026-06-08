class DSU {
    vector<int> par,size;
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> email2id;
        int n = accounts.size();
        DSU dsu(n);
        for(int i=0; i<n; ++i) {
            for(int j=1; j<accounts[i].size(); ++j) {
                email2id[accounts[i][j]] = i;
            } 
        }
        for(int i=0; i<n; ++i) {
            for(int j=1; j<accounts[i].size(); ++j) {
                string email = accounts[i][j];
                dsu.unite(email2id[email], i);
            } 
        }
        unordered_map<int, set<string>> id2set;
        for(int i=0; i<n; ++i) {
            for(int j=1; j<accounts[i].size(); ++j) {
                string email = accounts[i][j];
                int par = dsu.find(email2id[email]);
                id2set[par].insert(email);
            } 
        }
        vector<vector<string>> res;
        for(auto& [id,st]: id2set) {
            res.push_back({accounts[id][0]});
            for(auto& email: st) {
                res.back().push_back(email);
            }
        }
        return res;
    }
};