class Solution {
public://dfs ->visoted nodes ko mark yes 
    //then iterate through each node and look if they were reachable or not
    void dfs(vector<vector<int>>& c,vector<bool>& vis,int i){
    vis[i]=true;
	for(int j=0;j<c.size();j++)
		if(c[i][j]==1 && !vis[j])
			dfs(c,vis,j);
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt=0;
        int n=isConnected.size();
        if(n==0)return 0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++)
	    {
		if(!vis[i])
		{
			cnt++;
			dfs(isConnected,vis,i);
		}
	    }
	return cnt;
    }
};