// https://leetcode.com/problems/divide-array-into-increasing-sequences/
class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        int size = nums.size();
        // map<int,int> tracker;
        int maxi_cnt = 0;
        int cur_cnt = 0;
        int cur_num = 0;
        for(auto n: nums){
            if(n == cur_num){
                cur_cnt += 1;
            }
            else{
                maxi_cnt = max(maxi_cnt, cur_cnt);
                cur_num = n;
                cur_cnt = 1;
            }
        }
        maxi_cnt = max(maxi_cnt, cur_cnt);
        
        if( (maxi_cnt*K) > size)
            return false;
        return true;
    }
};