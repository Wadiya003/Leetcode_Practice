class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> canreach(numCourses,vector<bool>(numCourses,0));
        vector<bool> result;
        for(auto &p : prerequisites) 
            canreach[p[0]][p[1]] = 1;
       
        for(int k=0;k<numCourses;k++){
            for(int i=0;i<numCourses;i++){
                for(int j=0;j<numCourses;j++){
                    canreach[i][j] = canreach[i][j] || (canreach[i][k] && canreach[k][j]);
                }
            }
        }
        for(auto &q : queries) 
            result.push_back(canreach[q[0]][q[1]]);
        return result;
    }
        
//         vector<bool> ans;
//         vector<vector<int>> adj(n);
//         for(auto it : prerequisites)
//         {
//             adj[it[0]].push_back(it[1]);
//         }
        
//         for(int i=0; i<queries.size(); i++)
//         {
//             vector<bool> visited(n, false);
//             res.push_back(dfs(queries[i][0], queries[i][1], adj, visited));
//         }
        
//         return res;
//     }
//     bool dfs(int s,int e,vector<vector<int>>& queries,vector<vector<int>> adj, vector<bool> &visited){
//   if(s==e){
//       return true;
//   }
//         visited[s]=true;
//         for(auto a:adj){
//           }
};