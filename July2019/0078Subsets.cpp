// https://leetcode.com/problems/subsets
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int size = 0;
        for(auto num: nums){
            size = res.size(); 
            res.push_back({num});
            for(int i = 0; i <size; i++){
                res.push_back(res[i]);
                res.back().push_back(num);
            }
        }
        res.push_back({});
        return res;
    }
};