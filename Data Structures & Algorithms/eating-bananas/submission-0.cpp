class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        auto check = [&](int k) {
            int time = 0;
            for(auto& x: piles) time += (x + k - 1) / k;
            return time <= h;
        };

        int low = 1, hi = *max_element(piles.begin(), piles.end());
        while(low <= hi) {
            int mid = low + ((hi - low) >> 1);
            if(check(mid)) hi = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
