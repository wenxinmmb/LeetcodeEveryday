// https://leetcode.com/problems/best-sightseeing-pair/
// Can refactor a lot 
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        pair<int,int> mono = {A[0], 0};
        int res = A[0] + A[1] - 1;
        int total = A[0], gain = 0;
        
        for(int i = 1; i < A.size(); i++){
            gain = mono.first + A[i] - i + mono.second;
            if(gain > res)
                    res = gain;
            
            if( (i + A[i]) > total ){
                    total = i + A[i];
                    mono = {A[i], i};
            }
        }
        return res;
    }
};