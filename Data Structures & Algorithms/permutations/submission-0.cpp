class Solution {
    vector<vector<int>> res;
    vector<int> nums, v;
    unordered_set<int> st;
    void solve() {
        if(v.size() == nums.size()) {
            res.push_back(v);
            return;
        }
        for(auto& x: nums) {
            if(st.count(x)) continue;
            v.push_back(x);
            st.insert(x);
            solve();
            v.pop_back();
            st.erase(x);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        solve();
        return res;
    }
};
