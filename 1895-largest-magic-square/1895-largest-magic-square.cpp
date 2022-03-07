class Solution {
public:
       vector<vector<int>>row;
        vector<vector<int>>col;
        vector<vector<int>>topdiag;
        vector<vector<int>>downdiag;
    bool isvalid(int x, int y, int k, int &M, int &N, vector<vector<int>> &gri){
        int rightDown = topdiag[x + k - 1][y + k - 1];
        int leftUp = ((x - 1) >= 0 && (y - 1) >= 0) ? (topdiag[x - 1][y - 1]) : 0;
        int diagDown = rightDown - leftUp;
        
        int leftDown =downdiag[x + k - 1][y];
        int rightUp = ((x - 1) >= 0 && (y + k) < N) ? (downdiag[x - 1][y + k]) : 0;
        int diagUp = leftDown - rightUp;
        
        // Check if all diagonal sums are equal
        if (diagUp!= diagDown) {
            return false;
        }
        
        // Check if all row sums are equal
        for (int i = x + 1, t = k - 1; i < M && t > 0; i++, t--) {
            int curPrefixSum = row[i][y + k - 1] - ((y - 1) >= 0 ? row[i][y - 1] : 0);
            int prevPrefixSum = row[i - 1][y + k - 1] - ((y - 1) >= 0 ? row[i - 1][y - 1] : 0);
            if (curPrefixSum != prevPrefixSum || curPrefixSum != diagUp) {
                return false;
            }
        }
        
        // Check if all column sums are equal
        for (int j = y + 1, t = k - 1; j < N && t > 0; j++, t--) {
            int curPrefixSum = col[x + k - 1][j] - ((x - 1) >= 0 ? col[x - 1][j] : 0);
            int prevPrefixSum = col[x + k - 1][j - 1] - ((x - 1) >= 0 ? col[x - 1][j - 1] : 0);
            if (curPrefixSum != prevPrefixSum || curPrefixSum != diagUp) {
                return false;
            }
        }
        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
       int M=grid.size();
        int N=grid[0].size();
        if(M==1|| N==1){
           return 1;}
        row=grid;
        col=grid;
        topdiag=grid;
        downdiag=grid;
         for (int i = 0; i < M; i++) {
            for (int j = 1; j < N; j++) {
                row[i][j] += row[i][j - 1];
            }
        }
        for (int i = 1; i < M; i++) {
            for (int j = 0; j < N; j++) {
                col[i][j] += col[i - 1][j];
            }
        }
         for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                topdiag[i][j] += topdiag[i - 1][j - 1];
            }
        }
        for (int i = 1; i < M; i++) {
            for (int j = N - 2; j >= 0; j--) {
                downdiag[i][j] += downdiag[i - 1][j + 1];
            }
        }
         int k = min(M, N);
        while (k != 1) {
            for (int i = 0; i < M && (i + k - 1) < M; i++) {
               for (int j = 0; j < N && (j + k - 1) < N; j++) {
                    if (isvalid(i, j, k, M, N, grid)) {
                        return k;
                    }
                }
            }
            k -= 1;
        }
        
        return 1;
    }
};