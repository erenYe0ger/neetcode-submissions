class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x) {
            int y = (INT_MAX - x%10) / 10;
            int z = (0ll + INT_MIN - x%10) /10;
            if(res > y || res < z) return 0;
            res = res*10 + x%10;
            x /= 10;
        }
        return res;
    }
};
