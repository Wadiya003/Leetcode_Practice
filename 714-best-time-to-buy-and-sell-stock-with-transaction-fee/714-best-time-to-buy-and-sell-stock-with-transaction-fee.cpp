class Solution {
public:
   
    int dp[50001][2];
    int solve(vector<int> &prices , int i , bool buy , int &fee){
        
        if(i == prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy){
    return dp[i][buy] = max(solve(prices , i+1 , false , fee)-prices[i], 
                            solve(prices , i+1 , buy , fee));
        }
        else{
    return dp[i][buy] = max(solve(prices , i+1 , true , fee)+prices[i]-fee ,                                              solve(prices , i+1 , buy ,fee));
        } 
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp , -1 , sizeof(dp));
        return solve(prices , 0 , true , fee);
   
    }
    
    
    //greedy
     // int buy = -prices[0], sell = 0;
     //    for(auto x: prices) {
     //        buy = max(buy, sell-x);
     //        sell = max(sell, buy+x-fee);
     //    }
     //    return sell;
};