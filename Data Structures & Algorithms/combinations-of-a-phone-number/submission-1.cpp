class Solution {
    vector<string> keyPad, res;
    string str = "";
    void solve(string& digits, int n, int i) {
        if(i == n) {
            res.push_back(str);
            return;
        }
        for(auto& ch: keyPad[digits[i]-'0']) {
            str += ch;
            solve(digits, n, i+1);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};

        keyPad.resize(10);
        keyPad[2] = "abc";
        keyPad[3] = "def";
        keyPad[4] = "ghi";
        keyPad[5] = "jkl";
        keyPad[6] = "mno";
        keyPad[7] = "pqrs";
        keyPad[8] = "tuv";
        keyPad[9] = "wxyz";

        int n = digits.size();
        solve(digits, n, 0);
        return res;
    }
};
