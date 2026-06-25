#include <bits/stdc++.h>
class Solution {
    int dp[20][2005];
    int solve(vector<int>& nums, int i, int target) {
        if(i >= nums.size()) return target == 0;
        int& memo = dp[i][target + 1000];
        if(memo != -1) return memo;
        return memo = solve(nums, i+1, target + nums[i]) + 
                        solve(nums, i+1, target - nums[i]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, target);
    }
};
