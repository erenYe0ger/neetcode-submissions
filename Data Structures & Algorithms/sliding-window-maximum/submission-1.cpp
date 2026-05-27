class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> res;
        for(int i=0; i<n; ++i) {
            while (!dq.empty() && 
                    nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k-1) {
                res.push_back(nums[dq.front()]);
                int j = i-k+1;
                if(dq.front() == j) dq.pop_front();
            }
        }
        return res;
    }
};
