class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        if(sum & 1) return false;
        vector<vector<int>> dp(n+1, vector<int>(sum/2+1, false));
        for(int i=0; i<=n; ++i) dp[i][0] = true;
        for(int i=n-1; i>=0; --i) {
            for(int target=1; target<=sum/2; ++target) {
                dp[i][target] = dp[i+1][target];
                if(target >= nums[i]) dp[i][target] |= dp[i+1][target-nums[i]];
            }
        }
        return dp[0][sum/2];
    }
};
