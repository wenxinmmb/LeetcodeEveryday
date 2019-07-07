// https://leetcode.com/problems/permutations
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        int z = 0;        
        for(auto num: nums){
            int size = res.size();
            for(int i=0; i<size; i++){
                res[i].push_back(num);
                for(int j = 0; j < z; j++){
                    vector<int> r = res[i];
                    swap(r[j], r[z]);
                    res.push_back(r);
                }
            }
            z++;
        }
        return res;
    }
};