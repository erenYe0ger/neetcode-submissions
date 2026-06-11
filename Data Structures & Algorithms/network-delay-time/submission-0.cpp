class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        typedef pair<int, int> P; // time, node
        vector<vector<P>> adj(n+1);
        for(auto& e: times) {
            int u = e[0], v = e[1], t = e[2];
            adj[u].push_back({t, v});
        }
        priority_queue<P, vector<P>, greater<P>> minHeap;
        minHeap.push({0, k});
        unordered_set<int> vis;
        int maxTime = 0;
        while(!minHeap.empty()) {
            auto [t, u] = minHeap.top(); minHeap.pop();
            if(vis.count(u)) continue;
            vis.insert(u);
            maxTime = t;
            for(auto& [t2, v]: adj[u]) {
                minHeap.push({t+t2, v});
            }
        }
        if(vis.size() < n) return -1;
        return maxTime;
    }
};
