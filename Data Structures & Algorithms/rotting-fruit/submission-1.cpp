class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        typedef vector<int> V;
        queue<V> q;
        int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == 2) q.push({i,j,0});
            }
        } 
        int res = 0;
        while(!q.empty()) {
            auto v = q.front(); q.pop();
            int i = v[0], j = v[1], time = v[2];
            res = max(res, time);
            for(int t=0; t<4; ++t) {
                int x = i+dx[t], y = j+dy[t];
                if(x >= m || x < 0 ||
                    y >= n || y < 0 ||
                    grid[x][y] != 1) continue;
                grid[x][y] = 2;
                q.push({x,y,time+1});
            }
        }
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == 1) return -1;
            }
        }
        return res;
    }
};
