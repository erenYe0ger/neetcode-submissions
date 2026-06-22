class Solution {
    vector<vector<int>> res;
    vector<int> vec;
    void solve(vector<int>& candidates, int n, int i, int target) {
        if(target == 0) {
            res.push_back(vec);
            return;
        }
        if(i == n) return;
        for(int j=i; j<n; ++j) {
            if(j > i && candidates[j-1] == candidates[j]) continue;
            if(candidates[j] > target) continue;
            vec.push_back(candidates[j]);
            solve(candidates, n, j+1, target-candidates[j]);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        solve(candidates, n, 0, target);
        return res;
    }
};
