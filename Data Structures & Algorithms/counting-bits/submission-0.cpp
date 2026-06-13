class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0; i<=n; ++i) {
            int cnt = 0;
            for(int b=0; b<32; ++b) {
                if(1 & (i>>b)) ++cnt;
            }
            res.push_back(cnt);
        }
        return res;
    }
};
