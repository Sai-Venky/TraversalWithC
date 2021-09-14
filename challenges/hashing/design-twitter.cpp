// https://leetcode.com/problems/design-twitter

class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int, vector<pair<int, int>>> user;
    unordered_map<int, unordered_set<int>> fol;  
    int ct=0;
    Twitter() { }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
      user[userId].push_back({ct++, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
      vector<int> out;
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
      fol[userId].insert(userId);
      
      for(auto itr=fol[userId].begin(); itr!=fol[userId].end();itr++) {
        for(auto tweet:user[*itr]) {
          q.push({tweet.first, tweet.second});
          if(q.size()>10) q.pop();
        }
      }
      
      while(!q.empty()) {
        out.push_back(q.top().second);
        q.pop();
      }
      reverse(out.begin(), out.end());
      return out;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
      fol[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
      if(fol[followerId].count(followeeId)) {
        fol[followerId].erase(followeeId);
      }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */