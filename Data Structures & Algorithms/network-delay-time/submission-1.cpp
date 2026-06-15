class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int inf = 1e9;
        typedef pair<int, int> P; // {time, node}
        vector<vector<P>> adj(n+1);
        for(auto& e: times) {
            int u = e[0], v = e[1], t = e[2];
            adj[u].push_back({t, v});
        }
        priority_queue<P, vector<P>, greater<P>> minHeap;
        minHeap.push({0, k});
        vector<int> cost(n+1, inf);
        cost[k] = 0;
        while(!minHeap.empty()) {
            auto [t, u] = minHeap.top(); minHeap.pop();
            if(t > cost[u]) continue;
            for(auto& [t2, v]: adj[u]) {
                if(t + t2 < cost[v]) {
                    cost[v] = t + t2;
                    minHeap.push({cost[v], v});
                }
            }
        }
        int maxTime = 0;
        for(int i=1; i<=n; ++i) {
            if(cost[i] == inf) return -1;
            maxTime = max(maxTime, cost[i]);
        }
        return maxTime;
    }
};
