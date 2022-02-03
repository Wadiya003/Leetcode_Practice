class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
       int steps=0; 
       int ans=0;//to store answer
       int i1 = 0, j1 =0;
  for(auto i = 0; i < grid.size(); ++i)
    for (auto j = 0; j < grid[0].size(); ++j) {
      if (grid[i][j] == 1) i1 = i, j1 = j;//start and end 
      else if (grid[i][j] != -1) ++steps; //no. of empty squares we can walk over
    }
  dfs(grid, i1, j1, ans, steps); //recursive function to count all the paths
  return ans;
    }
    
    
    void dfs(vector<vector<int>>& grid,int start , int end, int &ans, int count){
       //if out of range
        if(start>=grid.size() || start<0 || end >=grid[0].size() || end<0)return;
        if(grid[start][end]==-1)return;
        //reached end
        if(grid[start][end]==2){
            if(count==0)ans++;
            //cout<<"yes";
            return;
        }
        grid[start][end]=-1;//mark visited;
        count=count-1;
        //recursions
        dfs(grid, start,end-1,ans,count);
        dfs(grid, start,end+1,ans,count);
        dfs(grid,start-1,end,ans, count);
        dfs(grid,start+1,end,ans, count);
        //backtrack
        grid[start][end]=0;
    }
};
  
        
       
       