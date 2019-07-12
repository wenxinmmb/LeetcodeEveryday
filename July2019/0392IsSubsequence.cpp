// https://leetcode.com/problems/is-subsequence/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cnt = 0;
        int size = s.size();
        if(size == 0)
            return true;
        for (auto tt: t){
            if(tt == s[cnt]){
                cnt++;
                if(cnt == size)
                    return true;
            }
        }
        return false;
    }
};