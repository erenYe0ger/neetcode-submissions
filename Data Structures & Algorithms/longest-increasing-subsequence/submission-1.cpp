class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;
        for(auto& i: nums) {
            auto it = lower_bound(LIS.begin(), LIS.end(), i);
            if(it == LIS.end()) LIS.push_back(i);
            else *it = i;
        }
        return LIS.size();
    }
};
