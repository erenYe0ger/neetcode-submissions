#include <bits/stdc++.h>
class Solution {
    int dp[5005][2];
    int solve(int i, int status, vector<int>& prices) {
        if(i >= prices.size()) return 0;
        if(dp[i][status] != -1) return dp[i][status];
        int res;
        if(status == 1) {
            res = max(prices[i] + solve(i+2, 0, prices), solve(i+1, 1, prices));
        } else {
            res = max(solve(i+1, 0, prices), -prices[i] + solve(i+1, 1, prices));
        }
        return dp[i][status] = res;
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, prices);
    }
};