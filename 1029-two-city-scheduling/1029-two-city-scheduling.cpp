class Solution {
public://recursive
    int solve(int i, int x,int y,vector<vector<int>>& costs,int dp[101][101][101]){
        if(i>=costs.size()){
            return 0;
        }
        int a=INT_MAX,b=INT_MAX;
        if(dp[i][x][y]!=-1){
            return dp[i][x][y];
        }
        if(x){
            a=costs[i][0]+solve(i+1,x-1,y,costs,dp);
       
        }
        if(y){
            b=costs[i][1]+solve(i+1,x,y-1,costs,dp);
         
        }
        return dp[i][x][y]=min(a,b);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        int x=n/2;
        int y=n/2;
        int dp[101][101][101];
        memset(dp,-1,sizeof(dp));
        return solve(0,x,y,costs,dp);
        
    }
};