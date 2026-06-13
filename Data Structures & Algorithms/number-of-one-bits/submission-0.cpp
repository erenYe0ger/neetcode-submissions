class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        for(int b=0; b<32; ++b) {
            if(1 & (n>>b)) ++cnt;
        }
        return cnt;
    }
};
