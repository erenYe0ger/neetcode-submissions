class Solution {
    set<vector<int>> st;
    vector<int> subset;
    void solve(int i, vector<int>& nums, int n) {
        if(i >= n) {
            st.insert(subset);
            return;
        }
        // take
        subset.push_back(nums[i]);
        solve(i+1, nums, n);
        subset.pop_back();
        // not take
        solve(i+1, nums, n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        solve(0, nums, n);
        return vector<vector<int>> (st.begin(), st.end());
    }
};
