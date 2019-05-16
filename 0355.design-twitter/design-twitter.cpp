class Twitter {
public:
    unordered_map<int,unordered_set<int>> uu;
    unordered_map<int,vector<pair<int,int>>> ut;
    int id;// 这是时间戳，发的晚不代表tweetId就大。
    
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        ut[userId].emplace_back(pair(id++,tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> u(uu[userId].begin(),uu[userId].end());
        u.emplace(userId);
        vector<pair<int,int>> t;
        for(const auto &user:u){
            for(const auto tweet:ut[user]){
                t.emplace_back(tweet);
            }
        }
        sort(t.rbegin(),t.rend());  //使用r进行倒着排序，这个trick要记住！！！
        vector<int> result;
        for(int i=0;i<10 && i<t.size();i++) result.push_back(t[i].second);
        return result;
        
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        uu[followerId].emplace(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        uu[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */