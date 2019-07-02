// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// An Important Binary Search Question
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int minCap = weights[0];
        int maxCap = weights[0];
        for(int i = 1; i < weights.size(); i++){
            if(minCap < weights[i]){
                minCap = weights[i];
            }
            maxCap += weights[i];
        }
        if(D >= weights.size())
            return minCap;
        if(D == 1)
            return maxCap;
        
        int mid, acc, day;
        
        while(minCap < maxCap){
            mid = minCap/2 + maxCap/2;
            acc = 0;
            day = 1;          
            for(int i = 0; i < weights.size(); i++){
                
                acc += weights[i];
                if(acc > mid){
                    day += 1;
                    acc = weights[i];
                }
            }
            
            if(day > D){
                minCap = mid + 1;
            }
            else{
                maxCap = mid;
            }
        }
        
        return minCap;
    }
};