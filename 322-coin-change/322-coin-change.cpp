class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,INT_MAX));
        for(int i=0; i <=coins.size();i++){
            for(int j=0;j<=amount;j++){
            if(i==0){
                dp[i][j]=1e5;
          }
            else if(j==0){
                dp[i][j]=0;
        }
            else if(coins[i-1]>j){
                dp[i][j] = dp[i-1][j];
        }
           else 
                dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
            }
        }
        return dp[coins.size()][amount]!=1e5?dp[coins.size()][amount] :-1;      
    }
};