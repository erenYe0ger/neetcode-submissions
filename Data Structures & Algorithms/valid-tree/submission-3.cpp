class Solution {
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, int u, int p) {
        vis[u] = true;
        for(auto& v: adj[u]) {
            if(v == p) continue;
            if(vis[v]) return false;
            if(dfs(adj,vis,v,u) == false) return false;
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0) return n == 1;
        if(edges.size() != n-1) return false;
        vector<vector<int>> adj(n);
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int leaf;
        for(int i=0; i<n; ++i) {
            if(adj[i].size() == 1) {
                leaf = i; break;
            }
        }
        vector<bool> vis(n, false);
        if(dfs(adj,vis,leaf, -1) == false) return false;
        for(int i=0; i<n; ++i) {
            if(!vis[i]) return false;
        }
        return true;
    }
};
