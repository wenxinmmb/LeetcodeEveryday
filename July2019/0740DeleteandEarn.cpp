// https://leetcode.com/problems/delete-and-earn/
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> num_map;
        int max_num = 0;
        for(auto n:nums){
            num_map[n]++;
            max_num = max(max_num, n);
        }
        vector<int> tracker(4,0);
        // cout<<"max "<<max_num<<endl;
        int res = 0;
        for(int i=1; i<=max_num; i++){
            if(i > 2)
                tracker[i%4] = max(tracker[(i-2)%4], tracker[(i-3)%4]);
            if(i == 2)
                tracker[i%4] = tracker[(i-2)%4];
            
            auto it = num_map.find(i);
            if(it != num_map.end()){
                // cout << i<<": "<<num_map[i]<<" "<<i * num_map[i]<<" ";
                tracker[i%4] += (i * num_map[i]);
                
            }
            // cout<<tracker[i%4]<<endl;
            res = max(res,tracker[i%4]);
        }
        return res;
    }
};