// https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pos_max = 0, neg_min = 0, res = 0;
        
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] > 0){
                
                if(pos_max == 0)
                    pos_max = nums[i];
                else
                    pos_max *= nums[i];
                
                if(neg_min < 0)
                    neg_min *= nums[i];
            }
            else{
                int pos_temp = pos_max;
                pos_max = neg_min *nums[i];
                
                if(pos_temp == 0)
                    neg_min = nums[i];
                else
                    neg_min = pos_temp * nums[i];
            }
            // cout<< "pos: "<<pos_max<<" neg: "<<neg_min<<endl;
            res = max(res, pos_max);
            res = max(res, nums[i]);
        }
        return res;
    }
};