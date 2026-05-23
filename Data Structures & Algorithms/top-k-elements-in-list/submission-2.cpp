class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        vector<vector<int>> f2vi(n+1);
        unordered_map<int,int> mp;
        for(auto& i: nums) ++mp[i];
        for(auto& [i,f]: mp) f2vi[f].push_back(i);
        for(int f=n; f>=0; --f) {
            vector<int> v = f2vi[f];
            for(auto& i: v) res.push_back(i);
            if(res.size() == k) break;
        }
        return res;
    }
};
