class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(auto& t: tasks) ++freq[t-'A'];
        priority_queue<int> maxHeap;
        for(auto& f: freq) {
            if(f) maxHeap.push(f);
        }
        queue<pair<int,int>> q;
        int timer = 0;
        while(!maxHeap.empty() || !q.empty()) {
            if(maxHeap.empty()) timer = q.front().second;
            while(!q.empty() && q.front().second <= timer) {
                maxHeap.push(q.front().first);
                q.pop();
            }
            int top = maxHeap.top();
            maxHeap.pop();
            ++timer;
            if(--top > 0) q.push({top, timer+n});
        }
        return timer;
    }
};
