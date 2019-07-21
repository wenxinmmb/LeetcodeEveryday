//https://leetcode.com/problems/number-of-equivalent-domino-pairs/
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>,int> result;
        int res = 0;
        for(auto domi: dominoes){
            vector<int>cur = domi;
            if(cur[0] > cur[1]){
                swap(cur[0],cur[1]);
            }
            result[cur]++;
        }
        for(auto d: result){
            if(d.second > 1){
                int num = d.second;
                res += num*(num-1)/2;
            }
        }
        return res;
    }
    
};