class Solution {
public:
    //dfs
    int target;
    vector<int>tmp;
    void helper(vector<vector<int>>& graph,vector<vector<int>>& ans,int curr){
        tmp.push_back(curr);
        if(curr==target){
            ans.push_back(tmp);
        }
        else{
        for (int node: graph[curr]) {
            helper(graph,ans,node);
        }
        }
      
		 tmp.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if(graph.size()==0)return {};
        vector<vector<int>> ans;
        target=graph.size()-1;
        helper(graph,ans,0);
        return ans;
    }
};