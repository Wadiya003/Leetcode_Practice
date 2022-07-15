class Solution {
public:
    int recur(vector<vector<int>>&grid, int i, int j ){
      if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || !grid[i][j]) return 0;
        grid[i][j]=0;
        return 1+ recur(grid,i+1,j) +recur(grid,i-1,j) +recur(grid,i,j+1)     +recur(grid,i,j-1);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
     int ans=0;
      for(int i =0;i< grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]){
               int cnt= recur(grid,i,j);
                ans=max(ans,cnt);
            }
        }
      }
        return ans;
    }
};