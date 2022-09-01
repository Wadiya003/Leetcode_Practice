class Solution {
public:
    //dp[i]= gives maxsum considering all previous elements 
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++){
           int curmax=0;
           int bestyet=0;
           for(int j=1;j<=k && i-j>=0;j++){
               curmax=max(curmax, arr[i-j]);
               bestyet=max(bestyet, dp[i-j]+curmax*j);
           }
        dp[i]=bestyet;
        }
        return dp[n];
    }
};