// https://leetcode.com/problems/range-sum-query-2d-immutable/
// Improve performace
class NumMatrix {
public:
    vector<vector<int>> myMatrix;
    int col;
    NumMatrix(vector<vector<int>>& matrix) {
        myMatrix = matrix;
        int row = matrix.size();
        col = 0;
        if(row > 0)
            col = matrix[0].size();
        int sum = 0;
        for(int i = 0; i < col; i++){
            sum += matrix[0][i];
            myMatrix[0][i] = sum;
        }
        sum = 0;
        for(int j = 0 ; j < row; j++){
            sum += matrix[j][0];
            myMatrix[j][0] = sum;
        }
        for(int j = 1; j < row; j++){
            for(int i = 1; i <col; i++){
                myMatrix[j][i] += myMatrix[j][i-1] + myMatrix[j-1][i] - myMatrix[j-1][i-1]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(col == 0)
            return 0;
        int sum = myMatrix[row2][col2];
        if(col1 > 0)
            sum -= myMatrix[row2][col1-1];
        if(row1 > 0)
            sum -= myMatrix[row1-1][col2];
        if(col1 > 0 && row1 >0)
            sum += myMatrix[row1-1][col1-1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */