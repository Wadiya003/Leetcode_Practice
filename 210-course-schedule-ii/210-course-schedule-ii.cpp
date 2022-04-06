class Solution { 
public: //Topological sort
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
          int n=prerequisites.size();
          queue<int>q;
          int cnt=0;
          vector<vector<int>> graph(numCourses);
          vector<int>incoming(numCourses,0);
          for(int i=0;i<n;i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]); //adcacency list
            ++incoming[prerequisites[i][0]];
           }
           //courses that do not depend on any
          for(int i = 0;i < numCourses;i++){
            if(incoming[i] == 0)
                q.push(i);
          }
         int i=0;
         while(!q.empty()){
         int node=q.front();
            q.pop();
            ++cnt;
           ans.push_back(node);
          for(auto v : graph[node])
            {
                if(--incoming[v] == 0)
                    q.push(v);
            }
         }
        if(cnt==numCourses){
             return ans;
}return {};
    }
};