class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m =grid.size();
        int n =grid[0].size();
        int maxe=0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i =0;i< m;i++){
        for(int j=0;j< n ;j++){
          if(grid[i][j]!=0){
             int ans= helper(grid,i,j,visited,m,n);
              maxe=max(maxe,ans);
           }  
        }       
      }return maxe;
    }
int helper(vector<vector<int>>&grid, int start, int end , vector<vector<int>>&visited ,int m , int n){
if(start>=m || end>=n ||start <0 ||end<0 || visited[start][end]==1 || !grid[start][end])
    return 0;
        visited[start][end]=1;//mark visited
    //recursions
         int left =helper(grid,start-1,end,visited,m,n);
        int right =helper(grid,start+1,end,visited,m,n);
             int max1=max(left,right);
        int top=helper(grid,start,end-1,visited,m,n);
        int down=helper(grid,start,end+1,visited,m,n);
             int max2=max(top,down);
        int result =max(max1, max2) +grid[start][end];
      visited[start][end]=0;//backtrack
      return result;
    
    }
};