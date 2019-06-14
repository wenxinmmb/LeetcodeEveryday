https://leetcode.com/problems/2-keys-keyboard
class Solution {
public:
    int minSteps(int n) {
        vector<int> vec(n+1, -1);
        vec[1] = 0;
        int ind, step;
        for(int i = 1 ; i < (n+1); i++){
            step = i;
            ind = i+i;
            int val = vec[i] + 2;
            if(ind > n)
                break;
            
            if(vec[ind] == -1)
                vec[ind] = val;
            else if(vec[ind] > val)
                vec[ind] = val;
            
            int j = ind;
            ind += step;
            
            while(ind < n+1){
                val += 1;
                if(vec[ind] == -1)
                    vec[ind] = val;
                else if(vec[ind] > val)
                    vec[ind] = val;
                j = ind;
                ind += step;
            }
        }
        return vec[n];
    }
};