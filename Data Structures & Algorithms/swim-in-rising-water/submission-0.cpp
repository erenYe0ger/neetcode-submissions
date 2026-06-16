class Solution {
    int inf = 1e9;
    int minTime = inf, n;
    int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};
    vector<vector<int>> grid;
    vector<vector<bool>> vis;
    map<vector<int>, bool> dp;
    void dfs(int i, int j, int maxVal) {
        if(i >= n || j >= n || i < 0 || j < 0) return;
        if(vis[i][j]) return;
        maxVal = max(maxVal, grid[i][j]);
        if(i == n-1 && j == n-1) {
            minTime = min(minTime, maxVal);
            return;
        }
        vector<int> v = {i,j,maxVal};
        if(dp.count(v)) return;
        vis[i][j] = true;
        for(int t=0; t<4; ++t) {
            int x = i+dx[t], y = j+dy[t];
            dfs(x,y,maxVal);
        }
        vis[i][j] = false;
        dp[v] = true;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        vis.resize(n, vector<bool> (n, false));
        dfs(0,0,0);
        return minTime;   
    }
};
