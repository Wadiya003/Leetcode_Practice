class Solution {
public:
     int mod = pow(10,9) + 7;
    int helper(int row, int col, int maxMove, int x, int y,  int moves, vector<vector<vector<int>>> & dp){
        if(x < 0 || y < 0 || x >= row || y >= col){
            return 1;
        }
        if(moves == maxMove){
            return 0;
        }
        if(dp[moves][x][y] != -1){
            return dp[moves][x][y] % mod;
        }
        int ans = 0;
        ans = (ans + helper(row, col, maxMove, x, y - 1, moves + 1, dp)) % mod;
        ans  = (ans  + helper(row, col, maxMove, x - 1, y, moves + 1, dp)) % mod;
        ans  = (ans  + helper(row, col, maxMove, x + 1, y, moves + 1, dp)) % mod;
        ans  = (ans  + helper(row, col, maxMove, x, y + 1, moves + 1, dp)) % mod;
        dp[moves][x][y] = ans ;
        return dp[moves][x][y] % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
      vector<vector<vector<int>>>dp(maxMove+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        dp[maxMove][m][n] = helper(m, n, maxMove, startRow, startColumn, 0, dp);
        return dp[maxMove][m][n];

    }
};