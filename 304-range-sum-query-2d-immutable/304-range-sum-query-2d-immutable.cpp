class NumMatrix {
public:
     vector<vector<int>> m2;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        m2 = vector<vector<int>>(m+1,vector<int>(n+1,0));
        for(int i = 1 ; i <= m; i++){
        for(int j = 1; j <= n; j++){
             m2[i][j] = matrix[i-1][j-1] + m2[i-1][j] + m2[i][j-1] - m2[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return m2[row2+1][col2+1] - m2[row1][col2 + 1] - m2[row2 + 1][col1] + m2[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */