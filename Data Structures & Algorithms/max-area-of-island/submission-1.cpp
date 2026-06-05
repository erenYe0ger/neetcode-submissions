class Solution {
    typedef pair<int,int> P;
    int m,n;
    int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};
    int dfs(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 0;
        int cnt = 1;
        for(int t=0; t<4; ++t) {
            int x = i+dx[t], y = j+dy[t];
            if(x >= m || x < 0 ||
                y >= n || y < 0 ||
                grid[x][y] == 0) continue;
            cnt += dfs(grid, x, y);
        }
        return cnt;
    }
    int bfs(vector<vector<int>>& grid, int i, int j) {
        int cnt = 1;
        grid[i][j] = 0;
        queue<P> q; q.push(make_pair(i,j));
        while(!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            for(int t=0; t<4; ++t) {
                int x = r+dx[t], y = c+dy[t];
                if(x >= m || x < 0 ||
                    y >= n || y < 0 ||
                    grid[x][y] == 0) continue;
                ++cnt;
                grid[x][y] = 0;
                q.push(make_pair(x,y));
            }
        }
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j]) {
                    // res = max(res, dfs(grid, i, j));
                    res = max(res, bfs(grid, i, j));
                }
            }
        }
        return res;
    }
};
