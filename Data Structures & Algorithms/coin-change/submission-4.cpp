#include <bits/stdc++.h>
class Solution {
    int inf = 1e9;
    int dp[10][10005];
    int solve(vector<int>& coins, int amount, int i) {
        if(amount == 0) return 0;
        if(i >= coins.size() || amount < 0) return inf;
        int& memo = dp[i][amount];
        if(memo != -1) return memo;
        int cnt = inf;
        // take 
        cnt = min(cnt, 1 + solve(coins, amount-coins[i], i));
        // not take
        cnt = min(cnt, solve(coins, amount, i+1));
        return memo = cnt;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int cnt = solve(coins, amount, 0);
        return cnt == inf ? -1 : cnt;
    }
};
