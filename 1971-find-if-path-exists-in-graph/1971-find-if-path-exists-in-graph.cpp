class Solution {
public: //dfs 
     vector<bool>vis;
     vector<vector<int>>adj;
    void dfs(int node){
         vis[node] = 1;
         for(auto &it : adj[node])
         {
         if(vis[it]) continue;
         dfs(it);
         }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vis.resize(n,0);
        adj.resize(n);
    
    for(auto &it : edges){
        int u = it[0] , v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(source);
    return vis[destination];
    }
};