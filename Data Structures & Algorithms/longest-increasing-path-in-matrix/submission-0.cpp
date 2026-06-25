class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        typedef vector<int> V;
        priority_queue<V, vector<V>, greater<V>> minHeap;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                minHeap.push({matrix[i][j], i,j});
            }
        }
        int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};
        int res = 1;
        while(!minHeap.empty()) {
            auto vec = minHeap.top(); minHeap.pop();
            int val = vec[0], i = vec[1], j = vec[2];
            for(int t=0; t<4; ++t) {
                int x = i+dx[t], y = j+dy[t];
                if(x < 0 || x >= m || y < 0 || y >= n) continue;
                if(matrix[x][y] >= matrix[i][j]) continue;
                dp[i][j] = max(dp[i][j], 1+dp[x][y]);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
