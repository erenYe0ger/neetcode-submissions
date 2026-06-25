class Solution {
    map<vector<int>, int> dp;
    int solve(vector<int>& v) {
        int n = v.size();
        if(n == 1) return v[0];
        if(dp.count(v)) return dp[v];
        int res = 0;
        for(int i=0; i<n; ++i) {
            int x = v[i] * (i-1 >= 0 ? v[i-1] : 1) * (i+1 < n ? v[i+1] : 1);
            vector<int> v2;
            for(int j=0; j<n; ++j) {
                if(j != i) v2.push_back(v[j]);
            }
            int x2 = solve(v2);
            res = max(res, x + x2);
        }
        return dp[v] = res;
    }
public:
    int maxCoins(vector<int>& nums) {
        return solve(nums);
    }
};