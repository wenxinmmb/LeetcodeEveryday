// https://leetcode.com/problems/design-twitter/
class Twitter {
    class Tweet {
        public:
            int uid, tid, time;
            Tweet(int u, int t, int time) {
                uid = u;
                tid = t;
                this->time = time;
            }
    };
    
    class PqNode {
        public:
            int uid;
            list<Tweet>::iterator it;
        
            PqNode(int u, list<Tweet>::iterator i) {
                uid = u;
                it = i;
            }
    };
    
    class Comp {
        public:
            bool operator()(PqNode a, PqNode b) {
                return a.it->time < b.it->time;
            }
    };
    
    int time;
    unordered_map<int, list<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> following;
    
public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_front(Tweet(userId, tweetId, time));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        auto& fol = following[userId];
        priority_queue<PqNode, vector<PqNode>, Comp> pq;
        for (auto& f : fol) {
            if (!tweets[f].empty())
                pq.push({f, tweets[f].begin()});
        }
        if (!tweets[userId].empty())
            pq.push({userId, tweets[userId].begin()});
        vector<int> feed;
        while (feed.size() < 10) {
            if (pq.empty()) break;
            auto t = pq.top();
            pq.pop();
            feed.push_back(t.it->tid);
            t.it++;
            if (t.it != tweets[t.uid].end())
                pq.push(t);
        }
        return feed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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


 class Twitter {
    struct Tweet {
        int time;
        int id;
        Tweet(int time, int id) : time(time), id(id) {}
    };

    unordered_map<int, std::vector<Tweet>> tweets;           // [u] = array of tweets by u
    unordered_map<int, std::unordered_set<int>> following;   // [u] = array of users followed by u

    int time;

public:
    Twitter() : time(0) {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(time++, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        vector<pair<Tweet*, Tweet*>> h; // pair of pointers (begin, current)

        for (auto& u: following[userId]) {
            auto& t = tweets[u];
            if (t.size() > 0)
                h.emplace_back(t.data(), t.data() + t.size() - 1);
        }
        auto& t = tweets[userId]; // self
        if (t.size() > 0)
            h.emplace_back(t.data(), t.data() + t.size() - 1);

        auto f = [](const pair<Tweet*, Tweet*>& x, const pair<Tweet*, Tweet*>& y) {
            return x.second->time < y.second->time;
        };
        
        make_heap(h.begin(), h.end(), f);

        const int n = 10;
        vector<int> o;
        o.reserve(n);
        for (int i = 0; (i < n) && !h.empty(); ++i) {
            pop_heap(h.begin(), h.end(), f);
            auto& hb = h.back();
            o.push_back(hb.second->id);
            if (hb.first == hb.second--)
                h.pop_back();
            else
                push_heap(h.begin(), h.end(), f);
        }
        return o;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
