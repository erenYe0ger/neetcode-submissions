class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(n);
        vector<int> in(n,0);
        for(auto& vec: prereq) {
            int u = vec[0], v = vec[1];
            adj[v].push_back(u);
            ++in[u];
        }
        queue<int> q;
        for(int i=0; i<n; ++i) {
            if(in[i] == 0) q.push(i);
        }
        vector<int> res;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            res.push_back(u);
            for(auto& v: adj[u]) {
                --in[v];
                if(in[v] == 0) q.push(v);
            }
        }
        return res.size() == n ? res : vector<int> ();
    }
};
