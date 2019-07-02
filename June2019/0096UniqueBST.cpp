https://leetcode.com/problems/unique-binary-search-trees/
class Solution {
public:
    int numTrees(int n) {
        vector<int> nn(n+1,0);
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        nn[0] = 1;
        nn[1] = 1;
        nn[2] = 2;
        int temp, j;
        for(int i = 3 ; i < n + 1; i++ ){
            temp = i;
            j = 0;
            while(temp > 0){
                if(temp > 1)
                    nn[i] += 2*nn[i-j-1]*nn[j];
                else
                    nn[i] += nn[i-j-1]*nn[j];
                temp -= 2;
                j++;
            }    
        }
        return nn[n];
    }
};