class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    MedianFinder() {}
    
    void addNum(int x) {
        if(left.empty() || x <= left.top()) left.push(x);
        else right.push(x);
        if(right.size() == left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
        else if(left.size() == right.size() + 2) {
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if(left.size() > right.size()) return left.top();
        return (double) (left.top() + right.top()) / 2;
    }
};
