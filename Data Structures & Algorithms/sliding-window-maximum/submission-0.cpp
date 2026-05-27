class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();
        vector<int> res;
        for(int i=0; i<n; ++i) {
            ++mp[nums[i]];
            if(i >= k-1) {
                res.push_back(mp.rbegin()->first);
                int j = i-k+1;
                --mp[nums[j]];
                if(mp[nums[j]] == 0) mp.erase(nums[j]);
            }
        }
        return res;
    }
};
