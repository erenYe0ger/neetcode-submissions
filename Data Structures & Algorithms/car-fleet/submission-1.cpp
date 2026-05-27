class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        typedef pair<int,double> P;
        vector<P> cars;
        int n = position.size();
        for(int i=0; i<n; ++i) {
            double time = (target - position[i]) * 1.0 / speed[i];
            cars.push_back(make_pair(position[i], time));
        }
        sort(cars.begin(), cars.end(), [](P p1, P p2) {
            return p1.first < p2.first;
        });
        int i = n-1;
        int cnt = 1;
        for(int j=n-2; j>=0; --j) {
            if(cars[j].second > cars[i].second) {
                ++cnt;
                i = j;
            }
        }
        return cnt;
    }
};
