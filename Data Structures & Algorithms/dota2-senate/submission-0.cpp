class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size(), i = 0;
        vector<bool> busted(n, false);
        while(true) {
            if(busted[i]) {
                i = (i+1) % n;
                continue;
            }
            char t = (senate[i] == 'R') ? 'D' : 'R';
            int j = (i+1) % n;
            while(j != i) {
                if(senate[j] == t &&
                    busted[j] == false) {
                    busted[j] = true;
                    break;
                }
                j = (j+1) % n;
            }
            if(j == i) {
                return senate[i] == 'R' ? "Radiant" : "Dire";
            }
            i = (i+1) % n;
        }
        return "";
    }
};