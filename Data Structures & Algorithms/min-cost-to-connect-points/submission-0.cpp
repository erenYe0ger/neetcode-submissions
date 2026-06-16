class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), inf = 1e9;
        vector<bool> vis(n, false); // vis[i] = i-th node inside mst
        vector<int> minCost(n, inf); // minCost[i] = min cost of i-th node to connect with mst
        minCost[0] = 0;
        int totCost = 0;
        for(int i=0; i<n; ++i) {
            int u = -1;
            for(int j=0; j<n; ++j) {
                if(vis[j]) continue;
                if(u == -1 || minCost[j] < minCost[u]) u = j;
            }
            totCost += minCost[u];
            vis[u] = true;
            for(int v=0; v<n; ++v) {
                if(vis[v]) continue;
                int cost = abs(points[u][0]-points[v][0]) + abs(points[u][1]-points[v][1]);
                minCost[v] = min(minCost[v], cost);
            }
        }
        return totCost;
    }
};
