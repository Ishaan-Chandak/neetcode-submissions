class Twitter {
public:
    unordered_map<int, vector<int>> mp;
    stack<pair<int, int>> pq;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        pq.push({tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        stack<pair<int, int>> temp = pq;

        while(!temp.empty()) {
            auto k = temp.top();
            temp.pop();
            if(k.second == userId) ans.push_back(k.first);
            else if(find(mp[k.second].begin(), mp[k.second].end(), userId) != mp[k.second].end()) ans.push_back(k.first);

            if(ans.size() > 10) ans.pop_back();
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followeeId].push_back(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        erase(mp[followeeId], followerId);
    }
};
