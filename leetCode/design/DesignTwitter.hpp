// https://leetcode.com/problems/design-twitter/
class Twitter {
private:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, deque<tuple<int, unsigned int>>> tweet;
    unsigned int tweetCount = 0;
public:
    /** Initialize your data structure here. */
    Twitter() {
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_front(make_tuple(tweetId, tweetCount++));
        if (tweet[userId].size() > 10) {
            tweet[userId].pop_back();
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<tuple<deque<tuple<int, unsigned int>>::iterator, deque<tuple<int, unsigned int>>::iterator>> toGet;
        {
            auto it = tweet.find(userId);
            if (it != tweet.end() && it->second.size()) {
                //printf("%d-%d\n", userId, userId);
                toGet.push_back(make_tuple(it->second.begin(), it->second.end()));
            }
            for (auto &x : following[userId]) {
                it = tweet.find(x);
                if (it != tweet.end() && it->second.size()) {
                    //printf("%d-%d\n", userId, x);
                    toGet.push_back(make_tuple(it->second.begin(), it->second.end()));
                }
            }
        }
        //printf("getNewsFeed(%d), toGet: %d\n", userId, toGet.size());
        if (!toGet.size()) {
            return vector<int>();
        }

        vector<int> resp;
        for (int j = 0; j < 10; ++j) {
            bool shouldBreak = true;
            for (auto &x : toGet) {
                if (get<0>(x) != get<1>(x)) {
                    shouldBreak = false;
                    break;
                }
            }
            if (shouldBreak) {
                break;
            }
            
            int idx = -1;
            int len = toGet.size();
            for (int i = 0; i < len; ++i) {
                auto x = toGet[i];
                if (get<0>(x) != get<1>(x)) {
                    if (idx == -1 || get<1>(*get<0>(x)) > get<1>(*get<0>(toGet[idx]))) {
                        idx = i;
                    }
                }
            }
            resp.push_back(get<0>(*get<0>(toGet[idx])));
            toGet[idx] = make_tuple(get<0>(toGet[idx]) + 1, get<1>(toGet[idx]));
        }
        return resp;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].emplace(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].erase(followeeId);
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
 
