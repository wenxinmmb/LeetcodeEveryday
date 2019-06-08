//https://leetcode.com/problems/word-search/
// TODO: make the code cleaner
class Solution {
public:
    
    int p_length = 0;
    int p_c = 0;
    int p_r = 0;
    
    bool exist(vector<vector<char>>& board, string word) {
        p_length = word.size();
        
        p_c = board[0].size(); // number of column
        p_r = board.size(); // number of row
        
        for(int i = 0; i < p_r; i++ ){
            for(int j = 0; j < p_c; j++){
                if(board[i][j] == word[0]){
                    if(dfs(0, i, j, board, word))
                        return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(int count, int ri, int ci, vector<vector<char>>& board, string word){
        
        if(count == p_length)
            return true;
        
        if( (ri >= p_r) || (ci >= p_c) ||(ci < 0) ||(ri < 0) )
            return false;
        
        if(board[ri][ci] == word[count]){
            board[ri][ci] = '*';
            if(dfs(count+1, ri+1, ci,board,word))
                return true;
            if(dfs(count+1, ri-1, ci,board,word))
                return true;
            if(dfs(count+1, ri, ci+1,board,word))
                return true;
            if(dfs(count+1, ri, ci-1,board,word))
                return true;
            board[ri][ci] = word[count];
        }
        return false;
    }
};