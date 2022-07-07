class Solution {
public:
    //bfs : simultaneously start with all the rotten oranges 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int fresh=0;
        int ans=-1;
        for(int i =0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if( grid[i][j]==2){
                    q.push({i,j});
                    
                }
            }
        }
        vector<int> dir={-1,0,1,0,-1}; //used for finding all 4 adjacent coordinates
        while(!q.empty()){
            int size=q.size();
            while(size--){
            pair<int,int> p =q.front();
            q.pop();
                for(int i=0;i<4;i++)
                {
                    int r=p.first+dir[i];
                    int c=p.second+dir[i+1];
                if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() &&grid[r][c]==1)
                    {
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--;
                    }
                    
                }
            }
            ans++; 
        
        }
        if(fresh)return -1;
        if(ans==-1)return 0;
       
        return ans;    
    }
};