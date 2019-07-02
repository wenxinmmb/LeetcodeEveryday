class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
    
        while(label != 1){
            res.push_back(label);
            label /= 2;
        }
        res.push_back(label);
        reverse(res.begin(), res.end());
        int size = res.size()%2;
        
        int n = 2;
        for(int i=1;i<res.size();i++){
            int c = 2*n;
            if( (i%2) == size){
                res[i] = c - res[i]- 1+ n;
            }
            n = c;
        }
        return res;
    }
};