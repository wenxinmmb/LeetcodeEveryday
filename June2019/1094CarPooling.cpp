// https://leetcode.com/problems/car-pooling
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int seated = 0;
        map<int,int> tracker;
        for(auto tr: trips){
            int num = tr[0];
            tracker[tr[1]] += num;
            tracker[tr[2]] -= num;
        }
        for(auto it: tracker){
            seated += it.second;
            if(seated > capacity)
                return false;
        }
        return true;
    }
};