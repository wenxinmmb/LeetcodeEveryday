class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){
        map<int,int> set1, set2;
        int res = 0;
        for(auto a: A){
            for(auto b: B){
                set1[a+b]++;
            }
        }
        
        for(auto c: C){
            for(auto d: D){
                set2[c+d]++;
            }
        }
        
        for(auto kv: set1){
            int okv = 0 - kv.first;
            auto opk = set2.find(okv);
            if(opk != set2.end()){
                res += opk->second * kv.second;
            }
        }
        return res;
    }
};