class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row=grid[0].size();
        int col=grid.size();
        vector<vector<int>> ans(col, vector<int> (row));

    for(int i = 0; i < col; ++i)
        for(int j = 0; j < row; ++j)
            ans[(i + (j + k) / row) % col][(j + k) % row] = grid[i][j];

    return ans;
    }
};