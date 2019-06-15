// https://leetcode.com/problems/house-robber-ii/
// DP
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        int res = 0;
        vector<int> total(4, 0);
        if(size < 1)
            return 0;
        
        // steal the nums[0];
        if(size == 1)
            return nums[0];
        else if(size == 2)
            return max(nums[0], nums[1]);
    
        int inc = 0;
        for(int i = 0; i < size - 1; i++){
            inc = 0;
            total[i%4] =nums[i];
            
            if(i > 1)
                inc = total[(i-2)%4];
            if(i > 2 && (total[(i-3)%4] > inc))
                inc = total[(i-3)%4];
            total[i%4] += inc;
            // cout<< total[i] << " ";
            res = max(res, total[i%4]);
        }
        
        
        // not steal nums[0]
        total = vector<int>(4, 0);
        cout<<endl;
        for(int i = 1; i < size; i++){
            total[i%4] = nums[i];
            inc = 0;
            if(i > 1)
                inc = total[(i-2)%4];
            if(i > 2 && (total[(i-3)%4] > inc))
                inc = total[(i-3)%4];
            total[i%4] += inc;
            // cout<< total[i] << " ";
            if(total[i%4] > res)
                res = total[i%4];
        }
        return res;
    }
};