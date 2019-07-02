// https://leetcode.com/problems/bitwise-and-of-numbers-range/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        vector<int> m_dig, n_dig;
        int mm = m, nn = n;
        while ( mm != 0 ){
            m_dig.push_back( mm&1 );
            mm = mm >> 1;
            
        }
        while ( nn != 0 ){
            n_dig.push_back( nn&1 );
            nn = nn >> 1;
        }
        
        if(m_dig.size() != n_dig.size())
            return 0;
        
        int size = m_dig.size();
        int i = 0;
        for(i = size-1; i >= 0; i--){
            if(m_dig[i] != n_dig[i])
                break;
        }
        
        int res = 0;
        for(int j = size - 1 ; j >= 0 ; j--){
            res = res << 1;
            if(j > i)
                res += m_dig[j];
        }
        return res;
    }
};