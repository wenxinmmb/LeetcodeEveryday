// https://leetcode.com/problems/delete-operation-for-two-strings/
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word2.size() == 0)
            return word1.size();
        if(word1.size() == 0)
            return word2.size();
        
        vector<vector<int>>dis(word2.size(),vector<int>(word1.size(),0));
        
        int found = true;
        int found2 = true;
        if(word1[0] != word2[0]){
            dis[0][0] = 2;
            found = false;
            found2 = false;
        }
        for(int i = 1; i< word1.size(); i++){
            if(word1[i] == word2[0] && !found){
                dis[0][i] = i;
                found = true;
            }
            else{
                dis[0][i] = dis[0][i-1]+1; 
            }
        }
        for(int j = 1; j< word2.size(); j++){
            if(word2[j] == word1[0] && !found2){
                dis[j][0] = j;
                found2 = true;
            }
            else{
                dis[j][0] = dis[j-1][0]+1; 
            }
        }
        for(int j = 1; j < word2.size(); j++){
            for(int i = 1; i < word1.size(); i++){
                dis[j][i] = min(dis[j-1][i],dis[j][i-1]) + 1;
                if(word1[i] == word2[j])
                    dis[j][i] = min(dis[j][i], dis[j-1][i-1]);
                else
                    dis[j][i] = min(dis[j][i], dis[j-1][i-1]+2);
            }
        }
        return dis[word2.size()-1][word1.size()-1];
    }
};