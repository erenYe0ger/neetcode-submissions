class Solution {
public:
    int getSum(int a, int b) {
        int res = 0, carry = 0;
        for(int i=0; i<32; ++i) {
            int a_bit = 1 & (a >> i);
            int b_bit = 1 & (b >> i);
            res |= (a_bit ^ b_bit ^ carry) << i;
            carry = (a_bit & b_bit) | (b_bit & carry) | (carry & a_bit);
        }
        return res;
    }
};
