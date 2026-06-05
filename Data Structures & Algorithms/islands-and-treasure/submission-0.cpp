class Solution {
    const int inf = 2147483647;
    typedef vector<int> V;
    int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<V> q;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == 0) q.push({i,j,0});
            }
        }
        while(!q.empty()) {
            auto v = q.front(); q.pop();
            int i = v[0], j = v[1], steps = v[2];
            for(int t=0; t<4; ++t) {
                int x = i+dx[t], y = j+dy[t];
                if(x >= m || x < 0 ||
                    y >= n || y < 0 ||
                    grid[x][y] <= 0 ||
                    grid[x][y] <= steps+1) continue;
                grid[x][y] = steps+1;
                q.push({x,y,grid[x][y]});
            }
        }
    }
};
