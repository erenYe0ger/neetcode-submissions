class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        typedef pair<string, int> P; // string, dist
        queue<P> q; 
        q.push({beginWord, 1});
        unordered_set<string> words (wordList.begin(), wordList.end());
        words.erase(beginWord);
        while(!q.empty()) {
            auto [word, dist] = q.front(); q.pop();
            if(word == endWord) return dist;
            for(int i=0; i<word.size(); ++i) {
                string nextWord = word;
                for(char ch='a'; ch<='z'; ++ch) {
                    nextWord[i] = ch;
                    if(words.count(nextWord)) {
                        words.erase(nextWord);
                        q.push({nextWord, dist+1});
                    }
                }
            }
        }
        return 0;
    }
};
