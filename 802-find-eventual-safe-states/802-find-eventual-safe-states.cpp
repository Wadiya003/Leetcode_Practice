class Solution {
public://crux : reach a cycle or not ?? 
    //dfs find cycle : using color scheme (white, grey, black)
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n =graph.size();
        vector<int>ans;
        vector<bool>safe(n,false);
        vector<bool>vis(n,false);
         for(int i=0;i<n;i++){
            if(!vis[i]){
               dfs(i,safe,graph,vis);
            }
        }
        for(int i=0;i<n;i++){
            if(safe[i]){
               ans.push_back(i);
            }
        }
        return ans;
    }
    void dfs(int i, vector<bool>& safe, vector<vector<int>>& graph, vector<bool>& vis){
        vis[i]=true; //mark visited
        bool flag=true;
        for(auto x:graph[i])//visit all neighbors
        {
            if(!vis[x])//if neighbor not visited
            {
                dfs(x,safe,graph,vis); //run dfs
            }
            flag=flag & safe[x]; //set flag true only if its safe to visit neighbour
        }
        safe[i]=flag;
    }
};