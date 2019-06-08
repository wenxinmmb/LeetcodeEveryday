// https://leetcode.com/problems/flip-string-to-monotone-increasing/

// TODO: can work on improving memory usage
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        vector<int> pos; int count = 0; int length = S.size();
        for(int i = 0 ; i < length; i++){
            if(S[i] == '1')
            {
                count++;
                pos.push_back(i);
            }
        }
        int minCount = count;
        for(int j = 0; j < pos.size(); j++){
            minCount = min(minCount, j + (length - pos[j] - count + j));
        }
        return minCount;
    }
};