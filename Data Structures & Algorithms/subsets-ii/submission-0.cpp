class Solution {
    set<vector<int>> res;
    vector<int> nums, v;
    int n;
    void solve(int i) {
        if(i == n) {
            res.insert(v);
            return;
        }
        v.push_back(nums[i]);
        solve(i+1);
        v.pop_back();
        solve(i+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums; n = nums.size();
        solve(0);
        return vector<vector<int>> (res.begin(), res.end());
    }
};
