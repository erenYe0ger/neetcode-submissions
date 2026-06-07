class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> heap;
        for(auto& point: points) {
            int x = point[0], y = point[1];
            heap.push({x*x + y*y, x, y});
            if(heap.size() > k) heap.pop();
        }
        vector<vector<int>> res;
        while(!heap.empty()) {
            auto point = heap.top(); heap.pop();
            res.push_back({point[1], point[2]});
        }
        return res;
    }
};
