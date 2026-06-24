class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] = length of LIS ending at i
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i=0; i<n; ++i) {
            for(int j=0; j<i; ++j) {
                if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
