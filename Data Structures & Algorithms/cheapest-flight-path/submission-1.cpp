class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int inf = 1e9;
        typedef pair<int, int> P;
        typedef vector<int> V;
        vector<vector<P>> adj(n);
        for(auto& flight: flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<int> dist(n, inf);
        dist[src] = 0;
        priority_queue<V, vector<V>, greater<V>> minHeap;
        minHeap.push({0,src,0});
        while(!minHeap.empty()) {
            auto vec = minHeap.top(); minHeap.pop();
            int d = vec[0], u = vec[1], stops = vec[2];
            for(auto& [v, d2]: adj[u]) {
                if(d + d2 < dist[v] && (stops != k || v == dst)) {
                    dist[v] = d + d2;
                    minHeap.push({dist[v], v, stops+1});
                }
            }            
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
