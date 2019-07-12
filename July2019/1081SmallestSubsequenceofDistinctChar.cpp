// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
// important
class Solution {
public:
    string smallestSubsequence(string text) {
        vector<int> tt(26, 0);
        vector<int> used(26, 0);
        vector<char> res;
        for(auto t:text){
            tt[t-'a']++;
        }
        for(auto t:text){
            tt[t-'a']--;
            if(used[t-'a'] == 1){
                continue;
            }
            while(res.size() > 0 && res.back() > t && tt[res.back()-'a'] > 0){
                used[res.back()-'a'] = 0;
                res.pop_back();
            }
            used[t-'a'] = 1;
            res.push_back(t);
        }
        return string(res.begin(), res.end());
    }
};