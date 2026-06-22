class Node {
public:
    int time, id;
    Node* next = nullptr;
    Node(int time, int id) : time(time), id(id) {}
};

class Twitter {
    unordered_set<int> following[101];
    Node* tweets[101];
    int time;
public:
    Twitter() {
        time = 0;
        for(int i=0; i<101; ++i) {
            tweets[i] = new Node(-1, -1);
        }
    }
    
    void postTweet(int userId, int tweetId) {
        Node* dummy = tweets[userId];
        Node* curTweet = new Node(time++, tweetId);
        curTweet->next = dummy->next;
        dummy->next = curTweet;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<Node*> maxHeap;
        if(tweets[userId]->next) maxHeap.push(tweets[userId]->next);
        for(auto& followee: following[userId]) {
            if(tweets[followee]->next) maxHeap.push(tweets[followee]->next);
        }
        while(!maxHeap.empty() && res.size() < 10) {
            auto tweet = maxHeap.top(); maxHeap.pop();
            res.push_back(tweet->id);
            if(tweet->next) maxHeap.push(tweet->next);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);        
    }
};
