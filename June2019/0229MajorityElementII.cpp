// https://leetcode.com/problems/majority-element-ii/
// Boyer-Moore Majority Voting Algo
// Important
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cad0 = 0, cad1 = 1,c0 = 0,c1 = 0;
        vector<int> res;
        for(auto num:nums){
            if(cad0 == num){
                c0++;
            }
            else if(cad1 == num){
                c1++;
            }
            else if(c0 == 0){
                cad0 = num;
                c0 = 1;
            }
            else if(c1 == 0){
                cad1 = num;
                c1 = 1;
            }
            else{
                c0--;
                c1--;
            }
            
        }
        c0 = 0;c1=0;
        for(auto num:nums){
            if(num == cad0)
                c0++;
            if(num == cad1)
                c1++;
        }
        if(c0 > nums.size()/3)
            res.push_back(cad0);
        if(c1 > nums.size()/3)
            res.push_back(cad1);
        
        return res;       
    }
};