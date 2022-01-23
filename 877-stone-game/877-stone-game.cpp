class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
      
        vector<vector<int>>dp(n,vector<int>(n));
        
        
        for(int dis=0;dis<n;dis++){
            for(int i=0,j=dis;j<n;i++,j++){
               
                if(dis== 0) dp[i][j] = piles[i];
                else if(dis== 1) dp[i][j] = max(piles[i], piles[j]);
                else{
        int case1 = piles[i] + min(dp[i+2][j], dp[i+1][j-1]);
        int case2 = piles[j] + min(dp[i+1][j-1], dp[i][j-2]);
           dp[i][j] = max(case1,case2);
                
            }             }
          }
          return dp[0][n-1];
        }
    
};