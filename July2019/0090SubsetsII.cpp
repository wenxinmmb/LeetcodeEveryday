class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int,int> rs;
        vector<vector<int>> res;
        int number, size;
        
        for(auto num: nums){
            rs[num]++;
        }
        
        for(auto re: rs){
            number = re.first;
            size = res.size(); 
            
            res.push_back({number});
            
            for(int j = 0; j < re.second - 1;j++){
                res.push_back(res.back());
                res.back().push_back(number);
            }
            
            for(int i = 0; i <size; i++){
                res.push_back(res[i]);
                res.back().push_back(number);
                for(int j = 0; j < re.second - 1; j++){
                    res.push_back(res.back());
                    res.back().push_back(number);
                }
            }
        }
        res.push_back({});
        return res;
    }
};