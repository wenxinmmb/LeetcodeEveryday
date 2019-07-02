// https://leetcode.com/problems/shortest-path-in-binary-matrix/
class Solution {
public:
    queue<pair<int,int>> temp;
    int ii , jj;
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        ii = grid.size();
        jj = grid[0].size();
        if(grid[0][0] == 1)
            return -1;
        
        for(int i = 0; i < ii; i++){
            for(int j = 0; j < jj; j++){
                if(grid[i][j] == 1)
                    grid[i][j] = -1;
            }
        }
        grid[0][0] = 1;
        temp.push(make_pair(0,0));
        int count, i ,j;
        pair<int,int> cur;
        while(!temp.empty()){
            cur = temp.front();
            i = cur.first;
            j = cur.second;
            temp.pop();
            count = grid[i][j] + 1;
            if(i == (ii-1) && j == (jj -1))
                return grid[i][j];
            
            insert_queue(i,j+1,count, grid);
            insert_queue(i,j-1,count, grid);
            insert_queue(i+1,j+1,count, grid);
            insert_queue(i+1,j-1,count, grid);
            insert_queue(i+1,j,count, grid);
            insert_queue(i-1,j+1,count, grid);
            insert_queue(i-1,j-1,count, grid);
            insert_queue(i-1,j,count, grid);
        }
        return -1;
    }
    
    void insert_queue(int i ,int j, int count, vector<vector<int>>& grid){
        if(i >= 0 && i < ii && j >=0 && j < jj && !(i == 0 && j == 0)&& 
           grid[i][j] == 0 ){
            grid[i][j] = count;
            temp.push(make_pair(i, j));
        }
    }
    
};