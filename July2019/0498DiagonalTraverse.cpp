// https://leetcode.com/problems/diagonal-traverse/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int x = matrix.size();
        if(x == 0)
            return {};
        int y = matrix[0].size();
        if(y == 0)
            return {};
        
        vector<vector<int>> direc = {{0,1},{1,-1},{1,0},{-1,1}};
        int prev_dia = 3;
        int cur_dir = 0;
        int count = 1,i = 0, j = 0;
        vector<int> res = {matrix[0][0]};
        while (count < x * y){
            int i_n = i + direc[cur_dir][0];
            int j_n = j + direc[cur_dir][1];
            
            if (i_n >= x || j_n >= y || i_n < 0 || j_n < 0){
                int p = cur_dir;
                
                if(p == 0){
                    cur_dir = 2;
                }
                
                else if(p == 2){
                    cur_dir = 0;
                }
                
                else{
                    prev_dia = cur_dir;
                    if (i == 0 || i == x-1)
                        cur_dir = 0;
                    if (j == 0 || j == y-1)
                        cur_dir = 2;
                }
            }
            else{
                res.push_back(matrix[i_n][j_n]);
                i = i_n; j = j_n;
                if(cur_dir == 0 || cur_dir == 2){
                    if(prev_dia == 1)
                        cur_dir = 3;
                    else
                        cur_dir = 1;
                }
                count++;
                
            }
        }
        return res;
    }
};