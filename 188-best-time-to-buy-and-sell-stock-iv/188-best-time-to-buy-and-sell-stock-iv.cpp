class Solution {
public:int dp[1005][210];
    int maxProfit(int k, vector<int>& prices) {
     memset(dp,-1,sizeof(dp));
    return helper(2*k, prices, 0);
    }
     int helper(int k , vector<int> prices, int start ){
         int ans=0;
        if(start>=prices.size())return 0;
        if(k==0)return 0;
        if(dp[start][k]!=-1)return dp[start][k]; 
        int buy=(
            k%2==0);
        if(buy){
        ans =max(helper(k-1,prices, start+1)-prices[start] ,helper(k, prices, start+1          ));
        }
        else {
        ans=max(helper(k-1,prices,start+1)+prices[start],helper(k,prices,start+1 ));
        }return dp[start][k]=ans;
        
}
};

       
       
   