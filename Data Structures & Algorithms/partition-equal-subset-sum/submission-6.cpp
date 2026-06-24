class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        if(sum & 1) return false;
        vector<int> dp(sum/2+1, false);
        dp[0] = true;
        for(int i=n-1; i>=0; --i) {
            for(int target=sum/2; target>=1; --target) {
                if(target >= nums[i]) dp[target] |= dp[target-nums[i]];
            }
        }
        return dp[sum/2];
    }
};
