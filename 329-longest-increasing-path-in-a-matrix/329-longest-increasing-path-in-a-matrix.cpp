class Solution {
public:
    //a cell in the matrix as a node,
//a directed edge from node x to node y if x and y are adjacent and x's value < y's value
      vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
   
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int ans=0;
        if(!row) return 0;
        vector<vector<int>> Indegree(row, vector<int>(col));
        queue<pair<int, int>> q;
        for(int i=0;i <row;i++){
            for(int j=0;j< col;j++){
                for(auto d:dir){
                     int x = i + d[0];
                     int y = j + d[1];
                if(x >= 0 && x < row && y >= 0 && y < col){
                        if(matrix[x][y] < matrix[i][j]) 
                            Indegree[i][j]++;
                    }
                }
                //jiski zero ho use pehle lo
                if(!Indegree[i][j]) q.push({i, j});
            }  
        }
        //queue work
        while(!q.empty()){
          int s = q.size();
            while(s--){
                pair<int, int> t=q.front();
                q.pop();
                int cx=t.first;
                int cy=t.second;
            for(auto d:dir){
                int nx=cx+d[0];
                int ny=cy+d[1];
                  if(nx >= 0 && nx < row && ny >= 0 && ny < col ){
                        if(matrix[cx][cy] < matrix[nx][ny]  && --Indegree[nx][ny] == 0) 
                            q.push({nx,ny});
                    }
             }
                
         }ans++;
        }
        
        return ans;
    }
};