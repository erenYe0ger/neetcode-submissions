class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        for(int i=m-1; i>=0; --i) {
            for(int j=n-1; j>=0; --j) {
                if(i == m-1 && j == n-1) dp[j] = 1;
                if(j+1 < n) dp[j] += dp[j+1];
            }
        }
        return dp[0];
    }
};
