#include <bits/stdc++.h>
class Solution {
    int inf = 1e9;
    int dp[10][10005];
    int solve(vector<int>& coins, int amount, int i) {
        if(amount == 0) return 0;
        if(i >= coins.size()) return inf;
        int& memo = dp[i][amount];
        if(memo != -1) return memo;
        int cnt = 1e9;
        for(int j=0; j<=amount/coins[i]; ++j) {
            cnt = min(cnt, j + solve(coins, amount - j*coins[i], i+1));
        }
        return memo = cnt;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1, sizeof(dp));
        int cnt = solve(coins, amount, 0);
        return cnt == inf ? -1 : cnt;
    }
};
