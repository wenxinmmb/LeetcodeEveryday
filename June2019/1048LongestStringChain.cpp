//https://leetcode.com/problems/longest-string-chain/
// descent, simple DP problem

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), [](const string& lhs, const string& rhs){
                return lhs.size() < rhs.size();
                    
        });
        
        unordered_map<string,int> hmap;
        // int maxi;
        for(auto &word: words){
            int maxi = 1;
            for(int i = 0; i < word.size(); i++){
                string prev = word.substr(0, i) + word.substr(i + 1);
                maxi = max(maxi, hmap[prev] + 1);
            }        
            hmap[word] = maxi;
            // cout<<word<<" ";
        }
        
        int count = 0;
        for(auto &it: hmap){
            if(count < it.second)
                count = it.second;
        }
        return count;
    }
};