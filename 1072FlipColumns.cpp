//  1072. Flip Columns For Maximum Number of Equal Rows
// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> m;
        int count = 0;
        for(int i=0; i < matrix.size(); i++){
            string cur = getFlip(matrix[i]);
            m[cur]++;
        }
        for(auto &it: m){
            if(it.second > count)
                count = it.second;
        }
        return count;
    }
    
    string getFlip(vector<int>& v){
        bool flip = false;
        if(v[0] != 0)
            flip = true;
        string s = "";
        for(int i=0; i<v.size();i++){
            if(!flip)
                s += ('0'+ v[i]);
            else
                s += (v[i] == 0) ? '1' : '0';
        }
        // cout<<s<<endl;
        return s;
    }
};

// Given a matrix consisting of 0s and 1s, we may choose any number of columns in the matrix and flip every cell in that column.  Flipping a cell changes the value of that cell from 0 to 1 or from 1 to 0.

// Return the maximum number of rows that have all values equal after some number of flips. 
// Example 1:

// Input: [[0,1],[1,1]]
// Output: 1
// Explanation: After flipping no values, 1 row has all values equal.
// Example 2:

// Input: [[0,1],[1,0]]
// Output: 2
// Explanation: After flipping values in the first column, both rows have equal values.
// Example 3:

// Input: [[0,0,0],[0,0,1],[1,1,0]]
// Output: 2
// Explanation: After flipping values in the first two columns, the last two rows have equal values.