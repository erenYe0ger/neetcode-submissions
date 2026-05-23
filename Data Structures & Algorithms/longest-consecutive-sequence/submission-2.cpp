class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st (nums.begin(), nums.end());
        int res = 0;
        for(auto& i: nums) {
            if(!st.count(i-1)) {
                int len = 0;
                int j = i;
                while(st.count(j)) {
                    ++len, res = max(res, len);
                    ++j;
                }
            }
        }
        return res;
    }
};
