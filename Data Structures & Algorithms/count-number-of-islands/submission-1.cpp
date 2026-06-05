class Solution {
    typedef pair<int,int> P;
    int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};
    int m, n;
    void dfs(vector<vector<char>>& grid, vector<vector<bool>> &vis,
            int i, int j) {
        vis[i][j] = true;
        for(int t=0; t<4; ++t) {
            int x = i+dx[t], y = j+dy[t];
            if(x >= m || x < 0 ||
                y >= n || y < 0 || 
                grid[x][y] == '0' ||
                vis[x][y]) continue;
            dfs(grid, vis, x, y);
        }
    }
    void bfs(vector<vector<char>>& grid, vector<vector<bool>> &vis,
            int i, int j) {
        queue<P> q;
        q.push(make_pair(i, j));
        vis[i][j] = true;
        while(!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            for(int t=0; t<4; ++t) {
                int x = r+dx[t], y = c+dy[t];
                if(x >= m || x < 0 ||
                    y >= n || y < 0 || 
                    grid[x][y] == '0' ||
                    vis[x][y]) continue;
                vis[x][y] = true;
                q.push(make_pair(x, y));
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == '1' &&
                     !vis[i][j]) {
                    ++cnt;
                    // dfs(grid, vis, i, j);
                    bfs(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
};
