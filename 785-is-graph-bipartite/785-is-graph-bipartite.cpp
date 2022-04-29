class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==0)return 0;
        vector<int>color(n,0);
        queue<int>q;
        
        for (int i = 0; i < n; i++) {
            if (color[i]) continue;
            color[i] = 1;
            q.push(i);
            while(!q.empty()){
                int top=q.front();
            for(auto g:graph[top]){
             if(!color[g]){
                 color[g]=-color[top];
                 q.push(g);
                }
            else if(color[g]==color[top])
                return false;
                
            }
                q.pop();
        }
        
    }
        return true;
  }
    
};
                
                