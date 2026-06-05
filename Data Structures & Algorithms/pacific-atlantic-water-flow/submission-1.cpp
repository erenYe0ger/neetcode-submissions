class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        typedef pair<int,int> P;
        int m = heights.size(), n = heights[0].size();
        int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};
        vector<vector<int>> res;
        vector<vector<bool>> pacific(m, vector<bool> (n, false));
        vector<vector<bool>> atlantic(m, vector<bool> (n, false));
        queue<P> pacific_q, atlantic_q;
        for(int i=0; i<m; ++i) {
            pacific_q.push({i, 0});
            atlantic_q.push({i, n-1});
        }
        for(int j=0; j<n; ++j) {
            pacific_q.push({0, j});
            atlantic_q.push({m-1, j});
        }
        while(!pacific_q.empty()) {
            auto [i,j] = pacific_q.front(); pacific_q.pop();
            pacific[i][j] = true;
            for(int t=0; t<4; ++t) {
                int x = i+dx[t], y = j+dy[t];
                if(x >= m || x < 0 ||
                    y >= n || y < 0 ||
                    heights[x][y] < heights[i][j] ||
                    pacific[x][y]) continue;
                pacific[x][y] = true;
                pacific_q.push({x,y});
            }
        }
        while(!atlantic_q.empty()) {
            auto [i,j] = atlantic_q.front(); atlantic_q.pop();
            atlantic[i][j] = true;
            for(int t=0; t<4; ++t) {
                int x = i+dx[t], y = j+dy[t];
                if(x >= m || x < 0 ||
                    y >= n || y < 0 ||
                    heights[x][y] < heights[i][j] ||
                    atlantic[x][y]) continue;
                atlantic[x][y] = true;
                atlantic_q.push({x,y});
            }
        }
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
