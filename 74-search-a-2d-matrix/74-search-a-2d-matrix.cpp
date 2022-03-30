class Solution {
public: //binary search //treat it as array only
    // (row, col) -> row*n + col
    // i -> [i/n][i%n]

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0;
        int j=m-1;
        
        while(i < n && j >= 0)
        {
            if(matrix[i][j] == target)
                return true;
            if(target < matrix[i][j] )
                --j;
            else
                ++i;
        }
        return false;
    }
};