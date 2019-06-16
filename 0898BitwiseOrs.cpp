// https://leetcode.com/problems/bitwise-ors-of-subarrays/
// Complexity is O(30N)
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> res, temp, prev;
        for(auto num: A){
            temp={num};
            if(!prev.empty()){
                for(auto ele: prev){
                    temp.insert(ele|num);
                }
            }
            prev = temp; 
            for(auto ele: temp)
                res.insert(ele);
        }
        return res.size();
        
    }
};