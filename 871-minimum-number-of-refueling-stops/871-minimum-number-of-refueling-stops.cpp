class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n =stations.size();
         //dp: From first i fuels, we used j to get max dist
        vector<vector<long>>dp(n+1,vector<long>(n+1,0));
         //don't fuel at any station-> Farthest==startFuel
        for(int i=0;i<n+1;i++)
        dp[i][0]=startFuel;
        
        for(int i=1;i<n+1;i++){
            for(int j =1;j<n+1;j++){
                //didn't fuel up==equal to last stations val
                dp[i][j]=dp[i-1][j];
                 //refuel at current
            if(dp[i-1][j-1]>=stations[i-1][0]){
                //if can reach this station from pre
               
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+stations[i-1][1]);//take max dist
                }
            }
        }
        
        for(int i=0;i<n+1;i++){
            if(dp[n][i]>=target){
                return i;
            }
        }
        return -1;
    }
};