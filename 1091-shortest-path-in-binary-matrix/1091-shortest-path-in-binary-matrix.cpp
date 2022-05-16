class Solution {
public:// dp wont work as we are looking at 8 directions , we will need precalculated values of all directions
    //BFS is the modt optimal solution, we can find the shortest path and consider cell with 0 as the undireted edge from a cell
    bool check(int i , int j , vector<vector<bool>>&vis, vector<vector<int>>& grid ){
        int n=grid.size();
        if(i>=0 && i<n && j>=0 && j<n && grid[i][j]==0 && !vis[i][j])
            return true;
        return false;
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n =grid.size();
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        queue<pair<int, int>> q;//{coordinates}
        int ans=0;
        
        if(grid[0][0]==0){
            q.push({0,0});
            vis[0][0]=true;
        }
        
        
        while(!q.empty()){
            int size=q.size();
            ans++;
            for(int i =0;i<size;i++){
                pair<int,int>top=q.front();
                q.pop();
                if(top.first==n-1 && top.second==n-1)return ans;
                //serach for all direction
                for(int j=top.first-1;j<=top.first+1;j++){
                    for(int k =top.second-1;k<=top.second+1;k++){
                        if(check(j,k,vis,grid)){
                             q.push({j, k});
                            vis[j][k] = true;
                        }
                     }
                 }
            }
         }
        return -1;
    }
};