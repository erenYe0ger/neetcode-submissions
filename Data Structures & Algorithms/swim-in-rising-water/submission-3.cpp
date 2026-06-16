class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), inf = 1e9;
        vector<vector<int>> cost(n, vector<int>(n, inf));
        typedef vector<int> V;
        priority_queue<V, vector<V>, greater<V>> minHeap;
        minHeap.push({grid[0][0], 0,0});
        cost[0][0] = grid[0][0];
        int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};
        while(!minHeap.empty()) {
            auto v = minHeap.top(); minHeap.pop();
            int maxVal = v[0], i = v[1], j = v[2];
            if(cost[i][j] < maxVal) continue;
            for(int t=0; t<4; ++t) {
                int x = i+dx[t], y=j+dy[t];
                if(x < 0 || x >= n || y < 0 || y >= n) continue;
                if(cost[x][y] > max(maxVal, grid[x][y])) {
                    cost[x][y] = max(maxVal, grid[x][y]);
                    minHeap.push({cost[x][y], x,y});
                }
            }
        }   
        return cost[n-1][n-1];
    }
};
