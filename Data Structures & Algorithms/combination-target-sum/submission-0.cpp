class Solution {
    vector<vector<int>> res;
    vector<int> vec;
    void solve(vector<int>& nums, int n, int i, int target) {
        if(i == n) return;
        if(target == 0) {
            res.push_back(vec);
            return;
        }
        // take
        if(nums[i] <= target) {
            vec.push_back(nums[i]);
            solve(nums, n, i, target-nums[i]);
            vec.pop_back();
        }
        // not take
        solve(nums, n, i+1, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        solve(nums, n, 0, target);
        return res;
    }
};
