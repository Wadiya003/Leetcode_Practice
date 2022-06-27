class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
         unordered_map<int,vector<int>>m;
        for(auto i:edges){
            m[i[1]].push_back(i[0]);
        }
        
        vector<vector<int>>ans;
        for(int i =0;i< n ;i++){
            vector<bool> check(n, false);
            vector<int> temp;
            dfs(m,check,i);
            for(int j=0;j<n;j++){
            if(j!=i && check[j]==true){
             temp.push_back(j);
            }
            }
            ans.push_back(temp);
        }
        return ans;
    }
    void dfs(unordered_map<int,vector<int>> &m, vector<bool>& check, int i ){
      check[i]=true;
      for(auto a: m[i]){
      if(check[a]==false)
          dfs(m,check,a);
      }
    }
};