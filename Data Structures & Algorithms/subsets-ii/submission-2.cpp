class Solution {
    vector<vector<int>> res;
    vector<int> subset;
    void solve(int i, vector<int>& nums, int n) {
        res.push_back(subset);
        for(int j=i; j<n; ++j) {
            if(j > i && nums[j-1] == nums[j]) continue;
            subset.push_back(nums[j]);
            solve(j+1, nums, n);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        solve(0, nums, n);
        return res;
    }
};
