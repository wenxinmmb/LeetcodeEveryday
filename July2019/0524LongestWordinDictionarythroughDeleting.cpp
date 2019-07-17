// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int ss = s.size();
        string res = "";
        for (auto dd: d){
            int j = 0;
            int i = 0;
            bool found = false;
            for(i = 0; i < dd.size(); i++){
                 while(j < ss){
                    if (s[j] == dd[i]){
                        if(i == dd.size()-1)
                            found = true;
                        j++;
                         break;
                    }
                     j++;
                 }
                
                if(j == ss){
                    break;
                }
            }

            if( found ){
                int cmp = dd.compare(res);
                if(dd.size() > res.size())
                    res = dd;
                else if(dd.size() == res.size() && cmp < 0){
                    res = dd;
                }
            }
        }
        return res;
    }
};