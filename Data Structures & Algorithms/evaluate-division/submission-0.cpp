class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int n = values.size(), id = 0;
        unordered_map<string,int> var2id;
        for(int i=0; i<n; ++i) {
            auto eq = equations[i];
            if(!var2id.count(eq[0])) var2id[eq[0]] = id++;
            if(!var2id.count(eq[1])) var2id[eq[1]] = id++;
        }
        typedef pair<double, int> P;
        vector<vector<P>> adj(id);
        for(int i=0; i<n; ++i) {
            auto eq = equations[i];
            double wt = values[i];
            int u = var2id[eq[0]], v = var2id[eq[1]];
            adj[u].push_back({wt, v});
            adj[v].push_back({1.0/wt, u});
        }

        auto bfs = [&](int u, int v) {
            queue<pair<double, int>> q;
            q.push({1, u});
            vector<bool> vis(id, false);
            vis[u] = true;
            while(!q.empty()) {
                auto [wt, node] = q.front(); q.pop();
                if(node == v) return wt;
                for(auto& [nextWt, next]: adj[node]) {
                    if(vis[next]) continue;
                    vis[next] = true;
                    q.push({wt*nextWt, next});
                }
            }
            return -1.0;
        };

        vector<double> res;
        for(auto& q: queries) {
            if(!var2id.count(q[0]) || !var2id.count(q[1])) {
                res.push_back(-1);
                continue;
            }
            res.push_back(bfs(var2id[q[0]], var2id[q[1]]));
        }
        return res;
    }
};