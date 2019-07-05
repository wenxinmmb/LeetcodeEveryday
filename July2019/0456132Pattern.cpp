// https://leetcode.com/problems/132-pattern/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        if(size < 3)
            return false;
        int bot = nums[0];
        int up = nums[0];
        bool is = false;
        vector<pair<int,int>> interval;
        
        for(int i = 1; i < size; i++){
            for(auto it: interval){
                if(nums[i] > it.first && nums[i] < it.second)
                    return true;
            }
            if(nums[i] > bot && nums[i] < up)
                return true;
            else if(nums[i] > up){
                up = nums[i];
            }
            else if(nums[i] < bot){
                if(bot != up)
                    interval.push_back({bot,up});
                bot = nums[i];
                up = nums[i];
            }            
        }
        return false;
    }
};