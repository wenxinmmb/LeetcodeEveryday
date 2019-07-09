// https://leetcode.com/problems/permutations-ii
class Solution {
    static int find(vector<int>& arr, int target){
        for(int i= arr.size()-1; i>=0; i--){
            if(arr[i] == target)
                return i;
        }
        return -1;
    }
    
public:
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int,int> nums_tracker;
        for(auto num: nums){
            nums_tracker[num]++;
        }
        
        vector<vector<int>> res;
        res.push_back({});
        int z = 0; int size = 0;        
        for (auto num: nums_tracker){
            for (int t = 0; t < num.second; t++) {
                size = res.size();
                for (int i = 0; i<size; i++) {
                    int q = find(res[i], num.first);
                    res[i].push_back(num.first);
                    for (int j = q + 1; j < z; j++) {
                        vector<int> r = res[i];
                        if (r[j] != r[z]) {
                            swap(r[j], r[z]);
                            res.push_back(r);
                        }
                    }
                }
                z++;
            }
        }
        return res;
    }
};