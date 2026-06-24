#include <bits/stdc++.h>
class Solution {
    int dp[100][5005];
    bool solve(vector<int>& nums, int i, int target) {
        if(target == 0) return true;
        if(i >= nums.size() || target < 0) return false;
        int& memo = dp[i][target];
        if(memo != -1) return memo;
        bool res = false;
        // take
        res |= solve(nums, i+1, target-nums[i]);
        // not take
        res |= solve(nums, i+1, target);
        return memo = res;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, sum/2);
    }
};
