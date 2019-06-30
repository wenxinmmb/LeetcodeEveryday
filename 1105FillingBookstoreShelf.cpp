// https://leetcode.com/problems/filling-bookcase-shelves/
// Important, Well designed DP question
class Solution {
public:
    int _width;
    vector<vector<int>> _book;
    
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        vector<int> dp (books.size(),-1);
        dp[0] = books[0][1];
        
        for(int i = 1; i < books.size(); i++){
            int height = dp[i-1] + books[i][1];
            int wid = books[i][0], h_h = books[i][1];
            for(int j = 1; j <= i; j++){
                wid += books[i-j][0];
                if(wid > shelf_width)
                    break;
                h_h = max(h_h, books[i-j][1]);
                if(i == j)
                    height = min(height, h_h);
                else
                    height = min(height, h_h + dp[i-j-1]);
            }
            dp[i] = height;
        }
        return dp[books.size()-1];
    }
    
    
};