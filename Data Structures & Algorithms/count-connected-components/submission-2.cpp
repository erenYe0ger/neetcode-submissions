class Solution {
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int u) {
        vis[u] = true;
        for(auto& v: adj[u]) {
            if(!vis[v]) dfs(adj,vis,v);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,false);
        int cnt = 0;
        for(int i=0; i<n; ++i) {
            if(!vis[i]) {
                ++cnt; 
                dfs(adj,vis,i);
            }
        }
        return cnt;
    }
};
