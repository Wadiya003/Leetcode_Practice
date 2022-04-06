class Solution {
public://For the tree-alike graph, the number of centroids is no more than 2
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
         vector<int>indegree(n,0),ans;
         int no=edges.size();
         queue<int>q;
           if(n==0)
            return {};
        if(n==1)
            return {0};
        for(int i=0;i<no;i++){
            graph[edges[i][1]].push_back(edges[i][0]);
             graph[edges[i][0]].push_back(edges[i][1]);//adcacency list 
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
           }
                
           //remove leaf nodes           
          for(int i = 0;i < n;i++){
            if(indegree[i] == 1)
                q.push(i);
         
          }
                                          
         while(!q.empty()){
            int s = q.size();
            ans.clear();
            for(int i=0; i<s;i++){
                int curr = q.front(); q.pop();
                ans.push_back(curr);
          for(auto &v : graph[curr])
            { indegree[v]--;
                if(indegree[v] == 1)
                    q.push(v);
            }
          }
        }
                                          
      
        return ans;
        
    }
};
        