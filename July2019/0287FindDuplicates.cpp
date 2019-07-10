// https://leetcode.com/problems/find-the-duplicate-number/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, size = nums.size();
        int hi = size-1, mid = 0;
        int chi = 0, clo = 0, cmid = 0;
        bool odd = false;
        if(size == 0)
            return 0;
        
        while(hi >= low){
            chi = 0; clo = 0; cmid = 0;
            odd = false;
            
            mid = low +  (hi-low)/2;
            if( (hi - low)%2 == 0 ){
                odd = true;
            }
            for(auto n: nums){
                if(n == mid){
                    cmid++;
                    if(!odd)
                        clo++;
                }
                else if(n < mid && n>= low)
                    clo++;
                else if(n > mid && n<= hi)
                    chi++;
            }
            if(cmid > 1)
                return mid;
            if(clo > chi)
                hi = mid-1;
            else
                low = mid+1;
        }
        return hi;
    }
};