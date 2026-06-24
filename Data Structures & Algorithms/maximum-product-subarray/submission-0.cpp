class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = 1, res = -20, negProd = -1;
        for(auto& i: nums) {
            prod *= i;
            res = max(res, prod);
            if(prod < 0) {
                if(negProd != -1) res = max(res, prod/negProd);
                else negProd = prod;
            }
            else if(prod == 0) prod = 1;
        }
        return res;
    }
};
