class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<bool> > atlantic, pacific;
    queue<pair<int, int> > q;
    int m,n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(!size(heights)) return ans;
        m = size(heights), n = size(heights[0]);
        atlantic = pacific = vector<vector<bool> >(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) 
            bfs(heights, pacific,i, 0),bfs(heights,atlantic,i,n- 1);
        for(int i = 0; i < n; i++) 
            bfs(heights, pacific, 0, i), bfs(heights,atlantic, m - 1, i);             
        return ans;

    }
    
    void bfs(vector<vector<int> >& v, vector<vector<bool> >& visited, int i, int j)
    {        
        q.push({i, j});
        while(!q.empty()){
            tie(i, j) = q.front(); q.pop();
            if(visited[i][j]) continue;
            visited[i][j] = true;
            if(atlantic[i][j] && pacific[i][j]) 
                ans.push_back(vector<int>{i, j});
            if(i + 1 <  m &&  v[i + 1][j] >=  v[i][j]) q.push({i + 1, j});
            if(i - 1 >= 0 &&  v[i - 1][j] >=  v[i][j]) q.push({i - 1, j});
            if(j + 1 <  n &&  v[i][j + 1] >=  v[i][j]) q.push({i, j + 1});
            if(j - 1 >= 0 &&  v[i][j - 1] >=  v[i][j]) q.push({i, j - 1});
        }
    }
};