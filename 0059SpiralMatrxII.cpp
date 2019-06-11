https://leetcode.com/problems/spiral-matrix-ii/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res ( n, vector<int>(n) );
        int k = 1, x = 0, y = 0, c = 0;
        while (k <= n*n){
            while (y < (n-c)){
                res[x][y] = k;
                y++;
                k++;
            }
            y = n - c - 1;
            x ++;
            while(x < (n-c)){
                res[x][y] = k;
                x++;
                k++;
            }
            x = n - c - 1;
            y--;
            while(y >= c){
                res[x][y] = k;
                y--;
                k++;
            }
            y = c;
            x--;
            while(x > c){
                res[x][y] = k;
                x--;
                k++;
            }
            c++;
            x = c;
            y = c;
        }
        return res;
    }
};