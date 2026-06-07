class Solution {
    vector<vector<int>> res;
    vector<int> nums;
    int n; 
    void solve(int i) {
        if(i == n) {
            res.push_back(nums);
            return;
        }
        for(int j=i; j<n; ++j) {
            swap(nums[i], nums[j]);
            solve(i+1);
            swap(nums[i], nums[j]);
        } 
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums; n = nums.size();
        solve(0);
        return res;
    }
};
