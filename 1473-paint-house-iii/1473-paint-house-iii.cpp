class Solution {
public:
     int dp[100][100][21];
    const int mx = 1e7+1;
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int target, int idx, int count, int prev){
        //base cases
        if(idx == houses.size()) return count==target ? 0 : mx;
        if(idx > houses.size()) return mx;
        if(dp[idx][count][prev]!=-1) return dp[idx][count][prev];
        int minCost = mx;
        if(houses[idx]){
        if(houses[idx]!=prev) 
            minCost = dfs(houses,cost,target,idx+1,count+1,houses[idx]);
            else minCost = dfs(houses,cost,target,idx+1,count,houses[idx]); 
        }else{
            for(int j=0;j<cost[0].size();j++){
                int tmp; 
                if((j+1)!=prev) 
                    tmp = cost[idx][j] + dfs(houses,cost,target,idx+1,count+1,j+1);
                else tmp = cost[idx][j] + dfs(houses,cost,target,idx+1,count,j+1);
                
                minCost = min(minCost,tmp);
            }
        }
        return dp[idx][count][prev] = minCost;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = dfs(houses,cost,target,0,0,0);
        if(ans==mx) return -1;
        else return ans;
    }
};