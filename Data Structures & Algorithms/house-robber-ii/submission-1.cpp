class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int dp0[101] = {0}, dp1[101] = {0};
        dp0[0] = 0, dp1[0] = nums[0];
        dp0[1] = nums[1], dp1[1] = max(nums[0], nums[1]);
        for(int i=2; i<n; ++i) {
            dp0[i] = max(dp0[i-2] + nums[i], dp0[i-1]);
            if(i < n-1) dp1[i] = max(dp1[i-2] + nums[i], dp1[i-1]);
            else dp1[i] = dp1[i-1];
        }
        return max(dp0[n-1], dp1[n-1]);
    }
};
