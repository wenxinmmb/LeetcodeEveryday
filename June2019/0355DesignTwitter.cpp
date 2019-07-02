// https://leetcode.com/problems/design-twitter/
class Twitter {
public:
    /** Initialize your data structure here. */
    int timestamp;
    map<int,vector<pair<int,int>>> twmap;
    map<int,set<int>> flmap;
    Twitter() {
        timestamp = 0;
        twmap = map<int,vector<pair<int,int>>>();
        flmap = map<int,set<int>>();
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        twmap[userId].push_back({timestamp, tweetId});
        timestamp++;
    }
    
    struct CustomCompare
    {
        bool operator()(const vector<int>& lhs, const vector<int>& rhs)
        {   
            return lhs[0] <= rhs[0];
        }
    };
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue< vector<int>,           
                        vector<vector<int>>,  
                        CustomCompare> q;
        
        set<int> flList = flmap[userId];
        flList.insert(userId);
        for(auto ele: flList){
            auto element = twmap.find(ele);
            if( element != twmap.end()){
                vector<pair<int,int>> &elevec = element->second;
                
                int ts = elevec[elevec.size()-1].first;
                int id = elevec[elevec.size()-1].second;
                q.push(vector<int>{ts, ele, elevec.size()-1, id});
            }
        }
        
        for(int i = 0; i <10; i++){
            if(q.empty())
                return res;
            vector<int> tt = q.top();
            q.pop();
            res.push_back(tt[3]);
            // cout<<tt[0]<<" "<<tt[1]<<" "<<tt[2]<<" "<<tt[3]<<endl;
            if(tt[2] > 0){
                int ts = twmap[tt[1]][tt[2]-1].first;
                int id = twmap[tt[1]][tt[2]-1].second;
                vector<int> nele{ts, tt[1], tt[2]-1, id};
                q.push(nele);
            }
        }
        return res;
    
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        flmap[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto it = flmap.find(followerId);
        if(it == flmap.end())
            return;
        set<int> & curVec = it->second;
        auto p = std::find (curVec.begin(), curVec.end(), followeeId);
        if(p == curVec.end())
            return;
        (curVec).erase(p);
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