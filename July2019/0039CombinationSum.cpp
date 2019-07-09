// https://leetcode.com/problems/combination-sum/
class Solution {
    class Entry{
        public:
        vector<int> _set;
        int _sum;
        Entry(vector<int>&set, int sum){
            _set = set;
            _sum = sum;
        }
    };
    
public:
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<Entry> resEn;
        
        for(auto can: candidates){
            vector<int> temp = {can};
            if(can == target)
            {
                res.push_back(temp);
                continue;
            }
            resEn.push_back(Entry(temp,can));
            int tt = 0;
            int size = resEn.size();
            
            for(int i=0; i<size; i++){
                tt = resEn[i]._sum;
                Entry en = resEn[i];
                while(tt < target){
                    en._set.push_back(can);
                    tt += can;
                    en._sum = tt;
                    if(tt > target)
                        break;
                    if(tt == target)
                        res.push_back(en._set);
                    else
                        resEn.push_back(en);
                }
            }
        }
        return res;
    }
};