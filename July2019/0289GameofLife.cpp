// https://leetcode.com/problems/game-of-life
// Inplace solution
class Solution {
public:
    int x_x = 0;
    int y_y = 0;
    void gameOfLife(vector<vector<int>>& board) {
        x_x = board.size();
        y_y = board[0].size();
        for(int x = 0; x < x_x; x++){
            for(int y = 0; y < y_y; y++){
                int sum = CheckSlot(x - 1,y-1, board) + CheckSlot(x-1, y, board) + 
                    CheckSlot(x - 1, y + 1, board) + CheckSlot(x + 1,y - 1, board) + 
                    CheckSlot(x + 1, y, board) + CheckSlot(x + 1, y + 1, board) +
                    CheckSlot(x, y - 1, board) + CheckSlot(x, y + 1, board);
                if(board[x][y] == 1){
                    if(sum ==2 ||sum ==3)
                        board[x][y] +=2;
                } else {
                    if(sum == 3)
                        board[x][y] +=2;
                }
            }
        }
        for(int x = 0; x < x_x; x++){
            for(int y = 0; y < y_y; y++){
                board[x][y] = (board[x][y]>>1) & 1;
            }
        }
        return;
    }
    
    int CheckSlot(int x, int y, vector<vector<int>>& board){
        if(x > -1 && x < x_x && y > -1 && y < y_y ){
            if( board[x][y] & 1 == 1)
                return 1;
        }
        return 0;
    }
};