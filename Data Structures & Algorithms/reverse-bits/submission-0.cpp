class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(int b=0; b<16; ++b) {
            // swap b-th bit and (31-b)th bit
            int x = (1 & (n>>b)) ^ (1 & (n>>(31-b)));
            n ^= (x << b);
            n ^= (x << (31-b));
        }
        return n;
    }
};
