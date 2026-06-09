class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> deg(n,0);
        for(auto& e: edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            ++deg[u]; ++deg[v];
        }
        queue<int> q;
        for(int i=0; i<n; ++i) {
            if(deg[i] == 1) q.push(i);
        }
        int cnt = n; // nodes left in the tree
        while(!q.empty()) {
            int sz = q.size();
            if(cnt <= 2) break;
            while(sz--) {
                --cnt;
                auto u = q.front(); q.pop();
                for(auto& v: adj[u]) {
                    --deg[v];
                    if(deg[v] == 1) q.push(v);
                }
            }
        }
        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front()); q.pop();
        }
        return res;
    }
};